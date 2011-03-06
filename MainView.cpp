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

static const rgb_color kDarkGrey = { 100, 100, 100, 255 };
static const rgb_color kHaikuGreen = { 42, 131, 36, 255 };
static const rgb_color kHaikuOrange = { 255, 69, 0, 255 };
static const rgb_color kHaikuYellow = { 255, 176, 0, 255 };
static const rgb_color kLinkBlue = { 80, 80, 200, 255 };


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
	fTextRanges.push_back(new TextRange(start, finish));
	SetFontAndColor(start, finish, be_plain_font, B_FONT_ALL, &kLinkBlue);
}

void
MainView::_ClearContours()
{
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
		BRegion region;		
	    GetTextRegion((*it)->start, (*it)->finish, &region);
	    for (int i = 0; i < region.CountRects(); i++) {
	    	SetHighColor(255,0,0);
	    	//printf("strok\n");
	    	StrokeRect(region.RectAt(i));
	    }
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
	BTextView::InsertText(text, length, offset, runs);
	fPythonPlugin.Func1(Text()/*text*/);	
}
