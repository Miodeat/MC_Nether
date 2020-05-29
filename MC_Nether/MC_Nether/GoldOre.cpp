#include "GoldOre.h"

GoldOre::GoldOre()
{
	const char* pa = ".\\data\\textures\\gold_ore.png";

	std::vector<const char*> paths;
	paths.push_back(pa);

	setupTexture(paths);
}

void GoldOre::getTextCoors(float*& textC)
{
	for (int i = 0; i < textCoorLen; i++) {
		textC[i] = this->textCoor[i];
	}
}

int GoldOre::getTextCoorLen()
{
	return textCoorLen;
}
