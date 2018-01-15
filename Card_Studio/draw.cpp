#include "draw.hpp"

#include <SDL.h>
extern SDL_Renderer *gRenderer;
extern const int SCREEN_WIDTH = 1600;
extern const int SCREEN_HEIGHT = 900;

void draw::drawData()
{
	SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 100);

	SDL_Rect rect = { 300,0,SCREEN_WIDTH - 750,SCREEN_HEIGHT - 30 };
	SDL_RenderDrawRect(gRenderer, &rect);
	rect = { 0,0,300,50 };
	SDL_RenderDrawRect(gRenderer, &rect);
	rect = { 0,150,300,SCREEN_HEIGHT - 180 };
	SDL_RenderDrawRect(gRenderer, &rect);
	//reset
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}
