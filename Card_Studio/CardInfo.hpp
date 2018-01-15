#pragma once

//klasse für Texture,
//soll außerdem zeigen welche Datei gerade aktiv ist etc

#include "TTF_Text.hpp"
#include "display_text.hpp"
#include "DefaultTexture.hpp"

#include <string>

class CardInfo
{
public:
	CardInfo(const std::string &path, std::string &name); //hand over .lua filename
	~CardInfo();

	bool reloadImg(const std::string &filename);

	void update(SDL_Event &e);
	void render();

	void setActive();
	void setInactive();

	SDL_Rect getData();

	void setPos(int x, int y);

	void set(int i, const std::string &newValue);
	std::string getPath(), getName(), getAttack(), getHealth(), getCost(), get(int i);

private:
	std::string mData[20];
	std::string mPath;
	std::string mImagePath;

	bool isActive;
	SDL_Rect mSizeData;

	TTF_Text mTextTexture; //list entry
	DefaultTexture mCardTexture;

	DefaultTexture mActive;
	DefaultTexture mInactive;
};

