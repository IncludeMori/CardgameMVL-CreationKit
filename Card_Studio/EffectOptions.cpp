#include "EffectOptions.hpp"



EffectOptions::EffectOptions()
{
}

EffectOptions::EffectOptions(Effect effect, Effect_Type effect_type)
{
}

void EffectOptions::update(SDL_Event & e)
{
}

void EffectOptions::render()
{
	
}

void EffectOptions::setPos(int x,int y)
{
	mPosX = x;
	mPosY = y;
}
void EffectOptions::setOption(Effect effect, Effect_Type effect_type)
{
}

void EffectOptions::updateFields()
{
	switch (mEffect)
	{
	case(Effect::BATTLECRY):

		InputField_Name.push_back("Target");
		InputField_Label.push_back(std::unique_ptr<TTF_Text>(new TTF_Text()));
		InputField_Label[InputField_Label.size() - 1]->loadFromRenderedText(InputField_Name[InputField_Name.size() - 1]+":");
		InputField.push_back({ mPosX,mPosY,150,50 });

		break;
	case(Effect::DEATHWISH):
		break;
	}
}

void EffectOptions::renderInputFields()
{
}

void EffectOptions::renderLabeling()
{
}


