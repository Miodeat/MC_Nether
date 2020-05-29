#include "Sand.h"

Sand::Sand()
{
	const char* pa = ".\\data\\textures\\sand.png";

	std::vector<const char*> paths;
	paths.push_back(pa);

	setupTexture(paths);
}

void Sand::getTextCoors(float*& textC)
{
	for (int i = 0; i < textCoorLen; i++) {
		textC[i] = this->textCoor[i];
	}
}

int Sand::getTextCoorLen()
{
	return textCoorLen;
}
