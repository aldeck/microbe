/*
 * Copyright 2011, Alexandre Deckner (alex@zappotek.com)
 * Distributed under the terms of the MIT License.
 *
 */


#include "TextRange.h"

#include <TextView.h>


TextRange::TextRange(BTextView* textView, int32 _start,
	int32 _finish, rgb_color _color)
{
	start = _start;
	finish = _finish;
	fTextView = textView;

	// clip range
	if (start < 0)
		start = 0;

	if (finish >= fTextView->TextLength())
		finish = fTextView->TextLength() - 1;

	fTextView->SetFontAndColor(start, finish, be_bold_font, B_FONT_ALL,
		&_color);
	fTextView->GetTextRegion(start, finish, &fRegion);

	color = _color;
};


TextRange::~TextRange()
{
	// TODO
};


void
TextRange::DrawContour(BTextView* view)
{
	int rectCount = fRegion.CountRects();
    for (int i = 0; i < rectCount; i++) {
    	view->SetHighColor(color);
    	view->StrokeRect(fRegion.RectAt(i));
    }
}
