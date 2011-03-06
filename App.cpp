/*
 * Copyright 2011, Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 * 		Alexandre Deckner <alex@zappotek.com>
 */

#include "App.h"

#include <Alert.h>

#include "MainWindow.h"


App::App()
	:
	BApplication("application/x-vnd.Haiku-Microbe")
{
	BRect frame(50, 50, 640 + 50, 480 + 50);
	const char *title = "Microbe";
	fMainWindow = new MainWindow(frame, title);
}


App::~App()
{
}


void App::AboutRequested()
{
	BAlert* alert;
	alert = new BAlert("About", "Microbe", "ok");
	alert->Go(NULL);
}


void App::MessageReceived(BMessage *message)
{
}


int
main(int argc, char** argv)
{
	App app;
	app.Run();
	return 0;
}
