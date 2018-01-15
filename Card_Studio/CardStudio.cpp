#include "CardStudio.hpp"

#include <string>
#include "GetFiles.hpp"
#include <vector>

#include "draw.hpp"
#include "FPS_Timer.hpp"
#include "StaticTextures.hpp"
#include "FileList.hpp"
#include "TTF_Text.hpp"
#include "display_text.hpp"
#include "gQuit.hpp"

extern SDL_Renderer *gRenderer;
#include "EventHandler.hpp"

CardStudio::CardStudio()
{
}


CardStudio::~CardStudio()
{
}

void CardStudio::loop()
{
	std::string p = "C:/Users/MoritzV/Desktop/Card_Game/CardGame_Walnut/Cards_Lua/";
	GetFiles AllFiles;
	std::vector<std::string> Filename = AllFiles.getFiles(p);
	
	
	draw drawx;
	SDL_Event e;
	Fps_Timer Timer;
	StaticTextures x;
	FileList list(p,Filename);
	Text text;
	//mainloop
	while (!gQuit)
	{
		Timer.start();
		Timer.calcFps();

		SDL_PollEvent(&e);
		//gg.handleEvent(e);
		SDL_RenderClear(gRenderer);

		list.update(e);
		x.render();
		list.render();
		//update
		//render
		drawx.drawData();

	
		SDL_RenderPresent(gRenderer);

		Timer.endFrame();
	}



}
