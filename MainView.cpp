/*
 * Copyright 2011, Alexandre Deckner (alex@zappotek.com)
 * Distributed under the terms of the MIT License.
 *
 */


#include "MainView.h"

#include <Region.h>

#include <stdio.h>

#include "Highlighter.h"


MainView::MainView(BRect frame)
	:
	//BTextView("MainView")
	BTextView(frame, "textview", frame,
		B_FOLLOW_ALL, B_FRAME_EVENTS | B_WILL_DRAW),
	fPythonPlugin(this, "klong")
{
	fHighlighter = new Highlighter(this);
	SetStylable(true);
	SetText(
		"// FIXME: Find nicer way to drop builtins and other cruft.\n"
		"int start_decl;\n"
	    "\n"
		"struct s0 {\n"
		"  int a;\n"
		"  int b;\n"
		"};\n"
		"\n"
		"struct s1;\n"
		"\n"
		"void f0(int a0, int a1) {\n"
		"  int l0, l1;\n"
		"\n"
		"  if (a0)\n"
		"    return;\n"
		"\n"
		"  for (;;) {\n"
		"    break;\n"
		"  }\n"
		"}\n"
		"}\n"
	);
}


MainView::~MainView()
{
}


status_t
MainView::Load(const entry_ref& ref)
{

}


Highlighter*
MainView::GetHighlighter() const
{
	return fHighlighter;
}


void
MainView::AttachedToWindow()
{
	BView::AttachedToWindow();
}


void
MainView::Draw(BRect updateRect)
{
	BTextView::Draw(updateRect);
	fHighlighter->Draw();
}


void
MainView::FrameResized(float width, float height)
{
}


void
MainView::Select(int32 start, int32 finish)
{
	BTextView::Select(start, finish);
}


void
MainView::DeleteText(int32 start, int32 finish)
{
	BTextView::DeleteText(start, finish);
	fPythonPlugin.Func1(Text()/*text*/);
}


void
MainView::InsertText(const char *text, int32 length, int32 offset,
	const text_run_array *runs)
{
	rgb_color black = { 0, 0, 0, 255};
	SetFontAndColor(be_plain_font, B_FONT_ALL, &black);

	BTextView::InsertText(text, length, offset, runs);
	bigtime_t start = system_time();
	fPythonPlugin.Func1(Text()/*text*/);
	printf("script time: %lims\n", (system_time() - start) / 1000);
}
