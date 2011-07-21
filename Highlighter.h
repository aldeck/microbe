/*
 * Copyright 2011, Alexandre Deckner (alex@zappotek.com)
 * Distributed under the terms of the MIT License.
 *
 */
#ifndef _HIGHLIGHTER_H
#define _HIGHLIGHTER_H


#include <GraphicsDefs.h>
#include <SupportDefs.h>

#include <vector>


class BTextView;
class TextRange;


static const rgb_color kBlack = { 0, 0, 0, 255 };
static const rgb_color kDarkGrey = { 0, 100, 100, 255 };
static const rgb_color kHaikuGreen = { 42, 131, 36, 255 };
static const rgb_color kHaikuOrange = { 255, 69, 0, 255 };
static const rgb_color kHaikuYellow = { 255, 176, 0, 255 };
static const rgb_color kLinkBlue = { 80, 80, 200, 255 };
static const rgb_color kPurple = { 80, 0, 80, 255 };


class Highlighter {
public:
								Highlighter(BTextView* parentView);
								~Highlighter();

			void				Highlight(int32 start, int32 finish,
									int32 color);
			void				ClearHighlights();
			void				Draw();

private:
			BTextView*			fTextView;

	typedef std::vector<TextRange*> TextRangeList;

			TextRangeList		fTextRanges;
};


#endif	// _MAINVIEW_H
