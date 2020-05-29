#include "DiamondOre.h"

DiamondOre::DiamondOre()
{
	const char* pa = ".\\data\\textures\\diamond_ore.png";

	std::vector<const char*> paths;
	paths.push_back(pa);

	setupTexture(paths);
}

void DiamondOre::getTextCoors(float*& textC)
{
	for (int i = 0; i < textCoorLen; i++) {
		textC[i] = this->textCoor[i];
	}
}

int DiamondOre::getTextCoorLen()
{
	return textCoorLen;
}
