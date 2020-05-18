#include "SoulSand.h"

SoulSand::SoulSand()
{

	const char* pa = ".\\data\\textures\\soul_sand.png";

	std::vector<const char*> paths;
	paths.push_back(pa);

	setupTexture(paths);
}

int SoulSand::getTextCoors(float*& textC)
{
	textC = this->textCoor;
	return 16;
}
