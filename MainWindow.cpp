/*
 * Copyright 2009, Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 * 		Alexandre Deckner <alex@zappotek.com>
 */

#include "MainWindow.h"

#include <Application.h>

#include <stdio.h>

#include "MainView.h"


MainWindow::MainWindow(BRect frame, const char* title)
	:
	BWindow(frame, title, B_TITLED_WINDOW_LOOK, B_NORMAL_WINDOW_FEEL, 0)
{
	fMainView = new MainView(Bounds());
	AddChild(fMainView);
	Show();
}


MainWindow::~MainWindow()
{
}


bool
MainWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}


void
MainWindow::MessageReceived(BMessage *message)
{
	switch (message->what) {
		default:
			BWindow::MessageReceived(message);
	}
}

