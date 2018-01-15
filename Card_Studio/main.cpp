#include <SDL.h>
#include <SDL_image.h>
#include "OpenFile.hpp"
#include "SaveFile.hpp"
#include <string>
#include <iostream>
#include "GetFiles.hpp"
#include "SDL_init.hpp"

#include "FPS_Timer.hpp"
#include "StaticTextures.hpp"
#include "draw.hpp"
#include "display_text.hpp"

#include "FileList.hpp"

#include "CardStudio.hpp"
#include "Mouse.hpp"

SDL_Renderer* gRenderer = nullptr;
SDL_Window* gWindow = nullptr;

//Window settings
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
const std::string WINDOW_NAME = "Card Studio";

Mouse gMouse;

int main(int argc, char* args[])
{
	

	SDL_init sdl;
	sdl.SDLinit(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);

	CardStudio CardStudio;

	CardStudio.loop();
	
	return 0;
}