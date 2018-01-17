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
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "1" << endl;
	
	draw drawx;
	SDL_Event e;
	Fps_Timer Timer;
	StaticTextures x;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "2" << endl;
	FileList list(p,Filename);
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "3" << endl;
	Text text;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "4" << endl;
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
