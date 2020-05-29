#include "NetherRack.h"

NetherRack::NetherRack()
{
	const char* pa = ".\\data\\textures\\soul_sand.png";

	std::vector<const char*> paths;
	paths.push_back(pa);

	setupTexture(paths);
}

void NetherRack::getTextCoors(float*& textC)
{
	for (int i = 0; i < textCoorLen; i++) {
		textC[i] = this->textCoor[i];
	}
}

int NetherRack::getTextCoorLen()
{
	return textCoorLen;
}
