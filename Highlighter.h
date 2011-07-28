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

#include <math.h>


class BTextView;
class TextRange;


static const rgb_color kBlack = { 0, 0, 0, 255 };


inline rgb_color
FloatRGB(float r, float g, float b);


rgb_color
HSVToRGB(float hue, float saturation, float value);


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
			rgb_color*			fPalette;
};


#endif	// _HIGHLIGHTER_H
