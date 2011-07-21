/*
 * Copyright 2011, Alexandre Deckner (alex@zappotek.com)
 * Distributed under the terms of the MIT License.
 *
 */
#ifndef _TEXT_RANGE_H
#define _TEXT_RANGE_H


#include <GraphicsDefs.h>
#include <Region.h>
#include <SupportDefs.h>


class BTextView;


class TextRange {
public:
								TextRange(BTextView* textView,
									int32 _start,
									int32 _finish,
									rgb_color _color);

								~TextRange();


			void				DrawContour(BTextView* view);

public:
			int32				start;
			int32				finish;
			rgb_color			color;

private:
			BRegion				fRegion;
			BTextView*			fTextView;
};


#endif	// _TEXT_RANGE_H
