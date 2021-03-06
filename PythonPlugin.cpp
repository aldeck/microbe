/*
 * Copyright 2011, Alexandre Deckner (alex@zappotek.com)
 * Distributed under the terms of the MIT License.
 *
 */


#include "PythonPlugin.h"

#include "Highlighter.h"
#include "MainView.h"


PythonPlugin* PythonPlugin::fInstance = NULL;


static PyMethodDef sMicrobeModuleMethods[] = {
   	{"select", PythonPlugin::_MicrobeSelectStatic, METH_VARARGS,
    	"Selects text in the editor."},
   	{NULL, NULL, 0, NULL}
};


PythonPlugin::PythonPlugin(MainView* mainView, const char* name)
	:
	fMainView(mainView)
{
	fInstance = this;

	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append(\"./plugins\");");

	Py_InitModule("microbe", sMicrobeModuleMethods);

	PyObject *pName = PyString_FromString(name); // TODO Error checking
	pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule == NULL) {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", name);
    } else {
        pFunc1 = PyObject_GetAttrString(pModule, "func1");
    	if (pFunc1 == NULL || !PyCallable_Check(pFunc1)) {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", "func1");

        	Py_XDECREF(pFunc1);
    	}
    }

}


PythonPlugin::~PythonPlugin()
{
	Py_XDECREF(pFunc1);
	Py_DECREF(pModule);
	Py_Finalize();
}


void
PythonPlugin::Func1(const char* text)
{
	if (pFunc1 != NULL) {

		fMainView->GetHighlighter()->ClearHighlights();

        PyObject *pArgs = PyTuple_New(1);
        PyObject *pValue = PyString_FromString(text);
        if (!pValue) {
           Py_DECREF(pArgs);
           fprintf(stderr, "Cannot convert argument\n");
           return;
        }
        PyTuple_SetItem(pArgs, 0, pValue);

        pValue = PyObject_CallObject(pFunc1, pArgs);
        Py_DECREF(pArgs);

        if (pValue != NULL) {
            printf("Result of call: %s\n", PyString_AsString(pValue));
            Py_DECREF(pValue);
        } else {
            PyErr_Print();
            fprintf(stderr,"Call failed\n");
            return;
        }
    }
}


PyObject*
PythonPlugin::_MicrobeSelect(PyObject *self, PyObject *args)
{
	int start = -1;
	int end = -1;
	int color = -1;

    if(!PyArg_ParseTuple(args, "iii:select", &start, &end, &color))
        return NULL;

    fMainView->GetHighlighter()->Highlight(start, end, color);

    return Py_BuildValue("i", 0);
}

