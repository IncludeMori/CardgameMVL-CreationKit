#include "InputField.hpp"

extern SDL_Renderer *gRenderer;

InputField::InputField()
{
}

InputField::InputField(int x, int y)
{
	mData.x = x;
	mData.y = y;
}

InputField::InputField(int x, int y, int w, int h)
{
	mData.x = x;
	mData.y = y;
	mData.w = w;
	mData.h = h;
}

InputField::InputField(const SDL_Rect & rect)
{
	mData = rect;
}

InputField::InputField(const SDL_Rect & rect, const std::string & text)
{
	loadFromRenderedText(text);
	mData = rect;
	CurrentValue = text;
}

InputField::~InputField()
{
}

void InputField::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	if (x != -1 && y != -1)
	{
		mPosX = x;
		mPosY = y;
	}
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { mPosX,mPosY, mWidth, mHeight };


	if (clip != nullptr)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	if (mIsActive)
		SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip); // renders texture to screen
	else
	{
		SDL_SetRenderDrawColor(gRenderer, 100,100,100,100);

		SDL_RenderFillRect(gRenderer, &mData);

		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
}

bool InputField::isActive()
{
	return mIsActive;
}

void InputField::set(bool b)
{
	mIsActive = b;
}
