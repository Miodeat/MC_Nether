#include "Cubic.h"

int Cubic::getVertex(float*& ver)
{
	ver = vertexs;
	return 24;
}

int Cubic::getIncides(int*& inci)
{
	inci = incides;
	return 36;
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

void Cubic::setupTexture(std::vector<const char*> paths)
{
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
