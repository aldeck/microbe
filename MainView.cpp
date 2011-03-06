/*
 * Copyright 2011, Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 * 		Alexandre Deckner <alex@zappotek.com>
 */

#include "MainView.h"

#include <Region.h>

#include <stdio.h>



MainView::MainView(BRect frame)
	:
	//BTextView("MainView")
	BTextView(frame, "textview", frame, 
		B_FOLLOW_ALL, B_FRAME_EVENTS | B_WILL_DRAW),
	fPythonPlugin(this)
{
	SetStylable(true);
	SetText("hello comment ca va?");
}


MainView::~MainView()
{
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
	//StrokeLine(BPoint(0,0), BPoint(100,100));
	_DrawTextRanges();
}


void
MainView::FrameResized(float width, float height)
{
}


void
MainView::_Contour(int32 start, int32 finish)
{
	fTextRanges.push_back(new TextRange(this, start, finish, kHaikuGreen));
}

void
MainView::_ClearContours()
{
	SetFontAndColor(0, TextLength(), be_plain_font, B_FONT_ALL, &kBlack);
	
	TextRangeList::iterator it = fTextRanges.begin();
	for(; it != fTextRanges.end(); it++) {
		delete (*it);
	}
	fTextRanges.clear();
}


void
MainView::_DrawTextRanges()
{
	TextRangeList::iterator it = fTextRanges.begin();
	for(; it != fTextRanges.end(); it++) {
		(*it)->DrawContour(this);
	}	
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
	SetFontAndColor(be_plain_font, B_FONT_ALL, &kBlack);
	
	BTextView::InsertText(text, length, offset, runs);
	fPythonPlugin.Func1(Text()/*text*/);	
}
