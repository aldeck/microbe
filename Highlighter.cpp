/*
 * Copyright 2011, Alexandre Deckner (alex@zappotek.com)
 * Distributed under the terms of the MIT License.
 *
 */


#include "Highlighter.h"

#include <TextView.h>

#include "TextRange.h"


Highlighter::Highlighter(BTextView* parentView)
	:
	fTextView(parentView)
{
}


Highlighter::~Highlighter()
{
}


void
Highlighter::Highlight(int32 start, int32 finish, int32 _color)
{
	rgb_color color;
	switch (_color) {
	case 1:
		color = kDarkGrey;
		break;
	case 2:
		color = kHaikuGreen;
		break;
	case 3:
		color = kHaikuOrange;
		break;
	case 4:
		color = kHaikuYellow;
		break;
	case 5:
		color = kDarkGrey;
		break;
	case 6:
		color = kLinkBlue;
		break;
	case 7:
		color = kPurple;
		break;
	default:
		color = kLinkBlue;
	};
	fTextRanges.push_back(new TextRange(fTextView, start, finish, color));
}


void
Highlighter::ClearHighlights()
{
	fTextView->SetFontAndColor(0, fTextView->TextLength(), be_plain_font,
		B_FONT_ALL, &kBlack);

	TextRangeList::iterator it = fTextRanges.begin();
	for (; it != fTextRanges.end(); it++) {
		delete (*it);
	}
	fTextRanges.clear();
}


void
Highlighter::Draw()
{
	TextRangeList::iterator it = fTextRanges.begin();
	for (; it != fTextRanges.end(); it++) {
		(*it)->DrawContour(fTextView);
	}
}
