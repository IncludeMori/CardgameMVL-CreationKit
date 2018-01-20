#include "CardInfo.hpp"

#include "sol\sol.hpp"
#include <iostream>
#include "eCardData.hpp"

extern SDL_Renderer *gRenderer;

CardInfo::CardInfo(const std::string &path, std::string &name)
{
	mActive.loadFromFile("Data/List/active.png");
	mInactive.loadFromFile("Data/List/inactive.png");

	//mName = name;
	mTextTexture.loadFromRenderedText(name);

	mSizeData.w = mActive.getWidth() + mTextTexture.getWidth()+20;
	mSizeData.h = mTextTexture.getHeight()+10;
	isActive = false;

	sol::state lua;
	std::cout << "Loading LuaFile:   " + path + "Data/card_effects_studio.lua" << std::endl;
	lua.script_file(path + "Data/card_effects_studio.lua");
	std::cout << "Loading LuaFile:   " + path + name << std::endl;
	lua.script_file(path + name);

	mPath = path + name;

	std::string Name = name.substr(0,name.find_last_of("."));

	mData[NAME] = Name;
	mPath = lua[mData[NAME]]["path"];
	std::cout << "path:" << mPath << std::endl;
	mData[ATTACK] = lua[mData[NAME]]["atk"];
	mData[HEALTH] = lua[mData[NAME]]["health"];
	mData[COST] = lua[mData[NAME]]["cost"];

	mData[EFFECT] = lua[mData[NAME]]["mEffect"];
    mData[EFFECT_TYPE] = lua[mData[NAME]]["mType"];

	if (mData[EFFECT_TYPE] == "Boost")
	{
		mData[TARGET] = lua[mData[NAME]]["mTarget"];
		mData[TARGET_SPEC] = lua[mData[NAME]]["mTarget_spec"];
		mData[STAT] = lua[mData[NAME]]["mStat"];
		mData[AMOUNT] = lua[mData[NAME]]["amount"];

	}

	std::string main_path = "Data/Cards_Png/Cards_Png/";
	mCardTexture.loadFromFile(main_path+Name+".png");
	mImagePath = main_path + mPath;

	/*
	Input_Name = { 500,150,500,50 };
	Input_Attack = { 500,200,500,50 };
	Input_Health = { 500,250,500,50 };
	Input_Cost = { 500,300,500,50 };

	TName.initText(mName);
	TAttack.initText(mAttack);
	THealth.initText(mHealth);
	TCost.initText(mCost);

	TName.setPos(500, 160);
	TAttack.setPos(500, 210);
	THealth.setPos(500, 260);
	TCost.setPos(500, 310);*/
}

CardInfo::~CardInfo()
{
	mTextTexture.free();
}

bool CardInfo::reloadImg(const std::string & filename)
{
	mCardTexture.free();
	if (!mCardTexture.loadFromFile(filename))
	{
		mCardTexture.loadFromFile(mImagePath);
		return false;
	}
	else
		return true;

}

void CardInfo::update(SDL_Event &e)
{
	//handle input and change text
	// check if mouse if above INPUT_
	// if true, activate
	// if active-> update text, change text

}

void CardInfo::render()
{
	mTextTexture.render();
	if (isActive)
	{
		mActive.render();
		mCardTexture.render(1200, 125);
	}
	else
		mInactive.render();


	SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 100);
	SDL_RenderDrawRect(gRenderer, &mSizeData);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void CardInfo::setActive()
{
	isActive = true;
}
void CardInfo::setInactive()
{
	isActive = false;
}

SDL_Rect CardInfo::getData()
{
	return mSizeData;
}

void CardInfo::setPos(int x, int y)
{
	mTextTexture.setPos(x + 20, y);
	mActive.setPos(x - 10, y + 10);
	mInactive.setPos(x - 10, y + 10);

	mSizeData.x = x - 20;
	mSizeData.y = y;
}


void CardInfo::set(int i, const std::string & newValue)
{
	mData[i] = newValue;
}

std::string CardInfo::getPath()
{
	return mPath;
}
std::string CardInfo::getName()
{
	return mData[NAME];
}
std::string CardInfo::getAttack()
{
	return mData[ATTACK];
}
std::string CardInfo::getHealth()
{
	return mData[HEALTH];
}
std::string CardInfo::getCost()
{
	return mData[COST];
}
std::string CardInfo::get(int i)
{
	if (i == 0)
		return mPath;
	return mData[i];
}