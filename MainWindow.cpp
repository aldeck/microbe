/*
 * Copyright 2011, Alexandre Deckner (alex@zappotek.com)
 * Distributed under the terms of the MIT License.
 *
 */


#include "MainWindow.h"

#include <Alert.h>
#include <Application.h>
#include <Entry.h>
#include <FilePanel.h>
#include <be_apps/Tracker/RecentItems.h>

#include <stdio.h>

#include "App.h"
#include "MainView.h"


const uint32 kMsgOpenFilePanel = 'opfp';


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
		case kMsgOpenFilePanel:
			fOpenPanel->Show();
			break;

		case B_REFS_RECEIVED:
		case B_SIMPLE_DATA:
			_MessageDropped(message);
			break;

		default:
			BWindow::MessageReceived(message);
			break;
	}
}


void
MainWindow::_MessageDropped(BMessage* message)
{
	status_t status = B_MESSAGE_NOT_UNDERSTOOD;
	bool hasRef = false;

	entry_ref ref;
	if (message->FindRef("refs", &ref) != B_OK) {
		const void* data;
		ssize_t size;
		if (message->FindData("text/plain", B_MIME_TYPE, &data,
				&size) == B_OK) {
			printf("text/plain %s\n", (const char*)data);
			// TODO revoir ce que faisait axel ici
			// surement deja dans textview en fait
		} else
			return;
	} else {
		/*status = fMainView->Load(ref);
		if (status == B_OK)
			be_roster->AddToRecentDocuments(&ref, kSignature);*/

		printf("ref = %s\n", ref.name);

		hasRef = true;
	}

	if (status < B_OK) {
		char buffer[1024];
		if (hasRef) {
			snprintf(buffer, sizeof(buffer),
				"Could not open \"%s\":\n%s\n", ref.name,
				strerror(status));
		} else {
			snprintf(buffer, sizeof(buffer),
				"Could not set text:\n%s\n",
				strerror(status));
		}

		(new BAlert("Microbe request",
			buffer, "OK", NULL, NULL,
			B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go();
	}
}
