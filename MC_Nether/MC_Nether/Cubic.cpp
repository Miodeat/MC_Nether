#include "Cubic.h"

void Cubic::getVertex(float*& ver)
{
	// copy vertexs array
	for (int i = 0; i < verLen; i++) {
		ver[i] = this->vertexs[i];
	}	
}

int Cubic::getVerLen()
{
	return verLen;
}

void Cubic::getNormal(float*& nor)
{
	for (int i = 0; i < norLen; i++) {
		nor[i] = this->normal[i];
	}
}

int Cubic::getNorLen()
{
	return norLen;
}

std::vector<int> Cubic::getTextWidths()
{
	return this->vecTextWidth;
}

std::vector<int> Cubic::getTextHeights()
{
	return this->vecTextHeight;
}

std::vector<int> Cubic::getNChannels()
{
	return this->vecTextNChannels;
}

std::vector<unsigned char*> Cubic::getTextData()
{
	return this->vecTextData;
}

float Cubic::getCubeWidth()
{
	return halfCubeWidth * 2;
}

void Cubic::setupTexture(std::vector<const char*> paths)
{
	stbi_set_flip_vertically_on_load(true);
	std::vector<const char*>::iterator it = paths.begin();
	while (it != paths.end())
	{
		int width, height, nChannels;
		unsigned char* data = stbi_load(*it, &width, &height, &nChannels, 0);
		this->vecTextData.push_back(data);
		this->vecTextWidth.push_back(width);
		this->vecTextHeight.push_back(height);
		this->vecTextNChannels.push_back(nChannels);

		it++;
	}
}
