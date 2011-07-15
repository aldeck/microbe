/*
 * Copyright 2011, Alexandre Deckner (alex@zappotek.com)
 * Distributed under the terms of the MIT License.
 *
 */
#ifndef _MAINVIEW_H
#define _MAINVIEW_H


#include <TextView.h>
#include <Region.h>

#include "PythonPlugin.h"

#include <vector>


static const rgb_color kBlack = { 0, 0, 0, 255 };
static const rgb_color kDarkGrey = { 0, 100, 100, 255 };
static const rgb_color kHaikuGreen = { 42, 131, 36, 255 };
static const rgb_color kHaikuOrange = { 255, 69, 0, 255 };
static const rgb_color kHaikuYellow = { 255, 176, 0, 255 };
static const rgb_color kLinkBlue = { 80, 80, 200, 255 };
static const rgb_color kPurple = { 80, 0, 80, 255 };


class TextRange {
public:
	TextRange(BTextView* textView, int32 _start, int32 _finish, rgb_color _color) {
		start = _start;
		finish = _finish;
		fTextView = textView;

		// clip range
		if (start < 0)
			start = 0;

		if (finish >= fTextView->TextLength())
			finish = fTextView->TextLength() - 1;

		fTextView->SetFontAndColor(start, finish, be_bold_font, B_FONT_ALL, &_color);
		fTextView->GetTextRegion(start, finish, &fRegion);

		color = _color;
	};

	//const BRegion* Region() const {
	//	return &fRegion;
	//}

	void DrawContour(BView* view) {
		/*int rectCount = fRegion.CountRects();
	    for (int i = 0; i < rectCount; i++) {
	    	view->SetHighColor(color);
	    	view->StrokeRect(fRegion.RectAt(i));
	    }*/
	}


	int32 start;
	int32 finish;
	rgb_color color;


private:
	BRegion fRegion;
	BTextView* fTextView;
};


class MainView : public BTextView {
public:
					MainView(BRect frame);
					~MainView();
	virtual void	Draw(BRect updateRect);
	void			_Contour(int32 start, int32 finish, int32 color);
	void			_ClearContours();
	void			_DrawTextRanges();

	virtual void	AttachedToWindow();
	virtual void	FrameResized(float width, float height);

	virtual void	Select(int32 start, int32 finish);
	virtual void	DeleteText(int32 start, int32 finish);
	virtual void	InsertText(const char *text, int32 length, int32 offset,
						const text_run_array *runs = NULL);

private:
			PythonPlugin fPythonPlugin;

	typedef std::vector<TextRange*> TextRangeList;
	TextRangeList fTextRanges;
};


#endif	// _MAINVIEW_H
