#pragma once

#include <vector>

#include "DefaultTexture.hpp"

class StaticTextures
{
public:
	StaticTextures();
	~StaticTextures();

	void render();

	void free();

private:
	DefaultTexture Files[10];
};

