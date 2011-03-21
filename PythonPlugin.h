/*
 * Copyright 2011, Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 * 		Alexandre Deckner <alex@zappotek.com>
 */
#ifndef _PYTHON_PLUGIN_H
#define _PYTHON_PLUGIN_H


#include <Python.h>

class MainView;

class PythonPlugin {
public:
					PythonPlugin(MainView* mainView, const char* name);
					~PythonPlugin();
					
	void			Func1(const char *text);
	
	PyObject*		_MicrobeSelect(PyObject *self, PyObject *args);

static PyObject*	_MicrobeSelectStatic(PyObject *self, PyObject *args)
					{
					    return fInstance->_MicrobeSelect(self, args);
					};
	
	/*virtual void	Select(int32 start, int32 finish);
	virtual void	DeleteText(int32 start, int32 finish);
	virtual void	InsertText(const char *text, int32 length, int32 offset);*/

private:
	static PythonPlugin* fInstance;
	
	PyObject *pModule, *pFunc1;
	MainView*		fMainView;
};


#endif	// _PYTHON_PLUGIN_H
