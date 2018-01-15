//
// @Author: Moritz Volkenandt (2017-)
//
// Used for: handles the next event on queue-> collection
//
#pragma once

#include <SDL.h>


class EventHandler
{
public:
	void handleEvent(SDL_Event &e);

	bool isMouseEvent(SDL_Event &e);
private:
};
