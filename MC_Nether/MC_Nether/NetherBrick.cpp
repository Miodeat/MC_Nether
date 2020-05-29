#include "NetherBrick.h"

NetherBrick::NetherBrick()
{
	const char* pa = ".\\data\\textures\\nether_brick.png";

	std::vector<const char*> paths;
	paths.push_back(pa);

	setupTexture(paths);
}

void NetherBrick::getTextCoors(float*& textC)
{
	for (int i = 0; i < textCoorLen; i++) {
		textC[i] = this->textCoor[i];
	}
}

int NetherBrick::getTextCoorLen()
{
	return textCoorLen;
}
