#include "Mouse.hpp"
#include <iostream>

Mouse::Mouse()
{
	update();
	mBtnPressed = false;
}

void Mouse::update()
{
	SDL_GetMouseState(&mPosX, &mPosY);

	if (mPosX < 0) { mPosX = 0; }
	if (mPosY < 0) { mPosY = 0; }
}

int Mouse::getX()
{
	return mPosX;
}
int Mouse::getY()
{
	return mPosY;
}
bool Mouse::isAbove(SDL_Rect &rect)
{
	if (mPosX > rect.x && mPosX < rect.x + rect.w && mPosY > rect.y && mPosY < rect.y + rect.h)
		return true;
	return false;
}