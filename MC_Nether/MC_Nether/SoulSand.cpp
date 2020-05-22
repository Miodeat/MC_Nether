#include "SoulSand.h"

SoulSand::SoulSand()
{

	const char* pa = ".\\data\\textures\\soul_sand.png";

	std::vector<const char*> paths;
	paths.push_back(pa);

	setupTexture(paths);
}

void SoulSand::getTextCoors(float*& textC)
{
	for (int i = 0; i < textCoorLen; i++) {
		textC[i] = this->textCoor[i];
	}
}

int SoulSand::getTextCoorLen()
{
	return textCoorLen;
}
