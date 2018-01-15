#include "TTF_Text.hpp"


extern SDL_Renderer *gRenderer;

TTF_Text::TTF_Text()
{
}
TTF_Text::TTF_Text(int size)
{
	mSize = size;
}
TTF_Text::TTF_Text(const std::string &text)
{
	loadFromRenderedText(text);
}
TTF_Text::~TTF_Text()
{
	free();
}


bool TTF_Text::loadFromRenderedText(int size, const std::string & textureText)
{
	mSize = size;
	return loadFromRenderedText(textureText);
}

bool TTF_Text::loadFromRenderedText(const std::string &textureText)
{

	TTF_Font *gFont = TTF_OpenFont("Data/Font/OpenSans-Italic.ttf", mSize);

	//Get rid of preexisting texture
	free();
	SDL_Color textColor = { 0,0,0 };

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == nullptr)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == nullptr)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;

			mData.w = mWidth;
			mData.h = mHeight;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	//Return success
	if (mTexture != nullptr)
		CurrentValue = textureText;
	return mTexture != nullptr;
}

std::string TTF_Text::AsString()
{
	return CurrentValue;
}


