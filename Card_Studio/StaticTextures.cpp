#include "StaticTextures.hpp"

enum Description {
	List,
	Preview,
	Data
};

StaticTextures::StaticTextures()
{
	std::string path = "Data/Static/"; //add filename

	Files[List].loadFromFile(path + "files.png");
	Files[List].setPos(0, 50);

	Files[Preview].loadFromFile(path + "preview.png");
	Files[Preview].setPos(1150, 0);

	Files[Data].loadFromFile(path + "data.png");
	Files[Data].setPos(650, 0);
}


StaticTextures::~StaticTextures()
{
	free();
}

void StaticTextures::render()
{
	for (int i = 0; i < 3; i++)
		Files[i].render();
}

void StaticTextures::free()
{
	for (int i = 0; i < 3; i++)
		Files[i].free();
}
