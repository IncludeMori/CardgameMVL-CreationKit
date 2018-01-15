#include "DropDownMenu.hpp"

#include "sol\sol.hpp"

#include <iostream>

#include "gMouse.hpp"
#include "ValidEntry.hpp"


#include <vector>

#define ACTIVE_FIELD_INT static_cast<int>(mActiveField)

enum {
	Effect,
	EffectType
};

DropDownMenu::DropDownMenu()
{
	mChoice = -1;

	background.loadFromFile("Data/Static/background_opt.png");
	sol::state lua; 
	lua.open_libraries(sol::lib::base);
	lua.script_file("C:/Users/MoritzV/Desktop/Card_Game/CardGame_Walnut/Cards_Lua/Data/card_effects_studio.lua"); //possible options

	//function to calc table size
	lua.script("function tablelength(T) local count = 0 for _ in pairs(T) do count = count + 1 end return count end"); 
	std::function<int(sol::table)> f = lua["tablelength"];
	std::function<int(sol::table)> fx = lua["ggg"];
	std::function<std::string(sol::table,int index)> getValue = lua["get"];

	//-----------------------
	//load tables from lua
	sol::table Table[5];
	Table[0] = lua["effect"];
	Table[1] = lua["etype"];

	Table[2] = lua["Target"];
	Table[3] = lua["target_spec"];
	Table[4] = lua["stat"];
	
	//save amount of options for 'effect'
	OptionsNmb.push_back(fx(Table[0])/2);
	OptionsNmb.push_back(f(Table[1])/2);

	OptionsNmb.push_back(f(Table[2]) / 2);
	OptionsNmb.push_back(f(Table[3]) / 2);
	OptionsNmb.push_back(f(Table[4]) / 2);
	
	//init and load different options
	std::string sub;
	std::vector<std::string> sub_options;
	for (int j = 0; j < MAX_OPTIONS; j++) //load options for all fields
	{
		for (int i = 0; i < OptionsNmb.at(j); i++) //get all sub-options
		{
			sub = getValue(Table[j], i);
			sub_options.push_back(sub);
		}
		mOptionsText.push_back(sub_options);
		sub_options.clear();
	}

	//init text texture
	std::vector<std::unique_ptr<DropField>> sub_textures;
	std::unique_ptr<DropField> current_text;

	for (int j = 0; j < MAX_OPTIONS; j++)
	{
		for (int i = 0; i < OptionsNmb.at(j); i++)
		{
			current_text.reset(new DropField);
			current_text->loadFromRenderedText(mOptionsText.at(j).at(i));
			sub_textures.push_back(std::move(current_text));
		}

		mOptions.push_back(std::move(sub_textures));

		std::cout << "PUSH:" << j << "---- Size:" << mOptions.at(j).size();
		sub_textures.clear();
	}

	printToCmd();
}


DropDownMenu::~DropDownMenu()
{
}

void DropDownMenu::setPos(Menu_Index data,int x, int y)
{
	//x += 100;
	x -= 60;
	y += 50;
	//switch (type)
	//{
	//}
	for (int j=0;j<mOptions.size();j++)
	for (int i=0; i< mOptions.at(j).size(); i++)
	     mOptions.at(j).at(i)->setPos(x, y+i*50);
}
void DropDownMenu::setActive(Menu_Index data)
{
	std::cout << "set to:" << static_cast<int>(data);
	mActiveField = data;

	if (mActiveField == Menu_Index::ERROR)
		mChoice = -1;
}

void DropDownMenu::update(SDL_Event &e)
{

	if (mChoice == -1)
		if (HandleEvent.isMouseEvent(e))
	{
		
		for (int i = 0; i < mOptions.at(ACTIVE_FIELD_INT).size(); i++)
		{
			if (mOptions.at(ACTIVE_FIELD_INT).at(i)->isActive())
			if (gMouse.isAbove(mOptions.at(ACTIVE_FIELD_INT).at(i)->getRect()))
			{
				mChoice = i;
				std::cout << "choice = " << i << std::endl;
			}
		}
	}
}
void DropDownMenu::render()
{
	for (int i = 0; i < mOptions.at(ACTIVE_FIELD_INT).size(); i++)
	{	
		if (mOptions.at(ACTIVE_FIELD_INT).at(i)->isActive())
		{
			background.render(mOptions.at(ACTIVE_FIELD_INT).at(i)->getX() - 20, mOptions.at(ACTIVE_FIELD_INT).at(i)->getY());
			mOptions.at(ACTIVE_FIELD_INT).at(i)->render();
		}
	}
}

void DropDownMenu::deactivateOption(Menu_Index index, const std::string & name)
{
	int index_name = -1;
	for (int i = 0; i < mOptionsText.at(static_cast<int>(index)).size(); i++)
		if (mOptionsText.at(static_cast<int>(index)).at(i) == name)
			index_name = i;

	std::cout << "set inactive:" << static_cast<int>(index) << ", name:" << name << std::endl;
	if (index_name != -1)
	mOptions.at(static_cast<int>(index)).at(index_name)->set(false);
	else
		for (int j = 0; j < MAX_OPTIONS; j++)
		{
			for (int i = 0; i < OptionsNmb.at(j); i++)
				mOptions.at(j).at(i)->set(true);
		}

	//stop rendering index_name, update x/y pos
	//mOptions.at(static_cast<int>(index)).at(index_name)
}

bool DropDownMenu::isActive()
{
	return mIsActive;
}

int DropDownMenu::getChoice()
{
	return mChoice;
}

std::string DropDownMenu::getAsString()
{
	std::cout << ACTIVE_FIELD_INT << "," << mChoice << std::endl;
	std::cout << "size:" << mOptions.size();
	return mOptionsText.at(ACTIVE_FIELD_INT).at(mChoice);
}

void DropDownMenu::printToCmd()
{
	std::cout << std::endl;
	for (int j = 0; j < mOptionsText.size(); j++)
	{
		for (int i = 0; i < mOptionsText[j].size(); i++)
		{
			std::cout << "j:" << j << ",i:" << i << ":" << mOptionsText.at(j).at(i) << std::endl;
		}
		std::cout << "------------------" << std::endl;
	}
}