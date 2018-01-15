//
// @Author: Moritz Volkenandt (2016-)
//
// Used for: handling mouse data
//
#pragma once

#include <SDL.h>

class Mouse
{
public:
	Mouse();
	
	void update(); //updates position & current status

	int getX(), getY();

	bool isAbove(SDL_Rect &rect);

private:
	int mPosX, mPosY;

	int mOldX, mOldY;
	int mX_df, mY_df;

	bool mBtnPressed;
	bool WheelUp, WheelDown;
};