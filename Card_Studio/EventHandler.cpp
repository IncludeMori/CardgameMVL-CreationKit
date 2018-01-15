#include "EventHandler.hpp"


#

#include <iostream>
//#include "gQuit.hpp"



void EventHandler::handleEvent(SDL_Event &e)
{
	//User requests quit
	if (e.type == SDL_QUIT)
	{
		//gQuit = true;
	} // event type -> SDL_QUIT X-Window
	/*
	else if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		gMouse.BtnDown();
	}
	else if (e.type == SDL_MOUSEBUTTONUP)
	{
		gMouse.BtnUp();
	}*/
	else
		if (e.button.button == SDL_BUTTON_LEFT && e.button.clicks == 2)
			std::cout << "WORKED";

}

bool EventHandler::isMouseEvent(SDL_Event &e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
		if (e.button.button == SDL_BUTTON_LEFT && e.button.clicks == 2)
		return true;
	else
		return false;

	return false;
}