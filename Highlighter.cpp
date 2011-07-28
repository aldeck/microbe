/*
 * Copyright 2011, Alexandre Deckner (alex@zappotek.com)
 * Distributed under the terms of the MIT License.
 *
 */


#include "Highlighter.h"

#include <TextView.h>

#include "TextRange.h"


inline rgb_color
FloatRGB(float r, float g, float b)
{
	rgb_color color = {(uint8)(b * 255.0f), (uint8)(g * 255.0f),
		(uint8)(r * 255.0f), 0};
	return color;
}


rgb_color
HSVToRGB(float hue, float saturation, float value)
{
	float f = hue / 60.0f - floor(hue / 60.0f);
	float p = value * (1 - saturation);
	float q = value * (1 - f * saturation);
	float t = value * (1 - (1 - f) * saturation);

	int32 intHue = (int32)floor(hue / 60.0f) % 6;
	//printf("intHue %li\n", intHue);
	switch (intHue) {
		case (0):
			return FloatRGB(value, t, p);
		case (1):
			return FloatRGB(q, value, p);
		case (2):
			return FloatRGB(p, value, t);
		case (3):
			return FloatRGB(p, q, value);
		case (4):
			return FloatRGB(t, p, value);
		case (5):
			return FloatRGB(value, p, q);
		default:
			return FloatRGB(0, 0, 0);
	}
}


Highlighter::Highlighter(BTextView* parentView)
	:
	fTextView(parentView)
{
	fPalette = new rgb_color[64];
	for (int i = 0; i < 64; i++) {
		fPalette[i] = HSVToRGB((float)i * 360.0f / 64.0f, 1.0f, 1.0f);
		//printf("rgb %u %u %u\n", rgb_color[i].red, rgb_color[i].green, rgb_color[i].blue);
	}
}


Highlighter::~Highlighter()
{
	delete [] fPalette;
}


void
Highlighter::Highlight(int32 start, int32 finish, int32 _color)
{
	rgb_color color;
	switch (_color) {
	case 1:
		color = fPalette[1];
		break;
	case 2:
		color = fPalette[10];
		break;
	case 3:
		color = fPalette[20];
		break;
	case 4:
		color = fPalette[30];
		break;
	case 5:
		color = fPalette[40];
		break;
	case 6:
		color = fPalette[50];
		break;
	case 7:
		color = fPalette[60];
		break;
	default:
		color = fPalette[64];
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
