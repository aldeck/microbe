/*
 * Copyright 2011, Alexandre Deckner (alex@zappotek.com)
 * Distributed under the terms of the MIT License.
 *
 */
#ifndef _MAINVIEW_H
#define _MAINVIEW_H


#include <TextView.h>

#include "PythonPlugin.h"

#include <vector>


class Highlighter;


class MainView : public BTextView {
public:
								MainView(BRect frame);
								~MainView();

	virtual void				Draw(BRect updateRect);

			status_t			Load(const entry_ref& ref);

			void				_DrawTextRanges();
			Highlighter*		GetHighlighter() const;

	virtual void				AttachedToWindow();
	virtual void				FrameResized(float width, float height);

	virtual void				Select(int32 start, int32 finish);
	virtual void				DeleteText(int32 start, int32 finish);
	virtual void				InsertText(const char *text,
									int32 length, int32 offset,
									const text_run_array *runs = NULL);

private:
			Highlighter* 		fHighlighter;
			PythonPlugin 		fPythonPlugin;
};


#endif	// _MAINVIEW_H
