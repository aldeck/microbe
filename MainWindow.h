/*
 * Copyright 2011, Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 * 		Alexandre Deckner <alex@zappotek.com>
 */
#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <Window.h>

class MainView;

class MainWindow : public BWindow {
public:
								MainWindow(BRect frame, const char* title);
								~MainWindow();

	virtual	bool				QuitRequested();
	virtual	void				MessageReceived(BMessage *message);

protected:
			MainView*			fMainView;
};

#endif	// _MAINWINDOW_H
