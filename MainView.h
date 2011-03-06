/*
 * Copyright 2011, Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 * 		Alexandre Deckner <alex@zappotek.com>
 */
#ifndef _MAINVIEW_H
#define _MAINVIEW_H


#include <TextView.h>

#include "PythonPlugin.h"

#include <vector>

struct TextRange {
	TextRange(int32 _start, int32 _finish) { start = _start; finish = _finish; };
	int32 start;
	int32 finish;
};	


class MainView : public BTextView {
public:
					MainView(BRect frame);
					~MainView();
	virtual void	Draw(BRect updateRect);
	void			_Contour(int32 start, int32 finish);
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
