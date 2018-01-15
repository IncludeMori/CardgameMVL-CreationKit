#pragma once

//Menu used to change Effects etc

#include <vector>
#include <memory>

#include "TTF_Text.hpp"
#include "StaticOptions.hpp"
#include "EventHandler.hpp"
#include "DropField.hpp"

class DropDownMenu
{
public:
	DropDownMenu();
	~DropDownMenu();

	void setPos(Menu_Index data,int x, int y);
	void setActive(Menu_Index field);

	void update(SDL_Event &e);
	void render();

	void deactivateOption(Menu_Index index, const std::string &name);

	bool isActive();
	int getChoice();
	std::string getAsString();
	

	void printToCmd();
private:
	EventHandler HandleEvent;

	bool mIsActive;
	int mChoice;
	Menu_Index mActiveField = Menu_Index::ERROR;

	DefaultTexture background;
	std::vector < std::vector<std::string>> mOptionsText;
	std::vector< std::vector<std::unique_ptr<DropField>>> mOptions; 
	std::vector<int> OptionsNmb;
	const int MAX_OPTIONS = 5;

};

