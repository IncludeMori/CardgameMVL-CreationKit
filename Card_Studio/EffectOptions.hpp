#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include <memory>

#include "StaticOptions.hpp"
#include "TTF_Text.hpp"

class EffectOptions
{
public:
	EffectOptions();
	EffectOptions(Effect effect, Effect_Type effect_type);
	
	void update(SDL_Event &e);
	void render();

	void setPos(int x, int y);

	void setOption(Effect effect, Effect_Type effect_type);




private:
	int mPosX, mPosY;

	Effect mEffect;
	Effect_Type mEffectType;

	std::vector<SDL_Rect> InputField;
	std::vector<std::unique_ptr<TTF_Text>> InputField_Label;
	std::vector<std::string> InputField_Name;

	//functions
	void updateFields();

	void renderInputFields();
	void renderLabeling(); 
};

