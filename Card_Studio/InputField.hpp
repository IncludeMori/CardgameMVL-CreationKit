#pragma once

#include "TTF_Text.hpp"

class InputField : public TTF_Text
{
public:
	InputField();
	InputField(int x,int y);
	InputField(int x, int y, int w, int h);
	InputField(const SDL_Rect &rect);
	InputField(const SDL_Rect &rect, const std::string &text);
	~InputField();

	void render(int x = -1, int y = -1, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

	bool isActive();
	
	void set(bool b);

protected:
	
	bool mIsActive;

};

