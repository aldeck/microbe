/*
 * Copyright 2011, Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 * 		Alexandre Deckner <alex@zappotek.com>
 */

#ifndef _APP_H
#define _APP_H

#include <Application.h>

class BWindow;

class App : public BApplication {

public:
								App();
								~App();

	virtual	void				AboutRequested();
	virtual void				MessageReceived(BMessage *message);
	
protected:
	BWindow*					fMainWindow;
};

#endif	// _APP_H
