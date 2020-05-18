#pragma once
#include <string>
#include <vector>
#include <stb_image.h>

// basic class of cubes.
// every cube should inherit this class publicly.
class Cubic
{
public:
	// get vertexs array
	//
	// @param ver: a reference of float pointer. 
	//             It will point to the first vertexs after calling.
	// @return: the number of vertexs
	int getVertex(float*& ver);

	// get incides array
	//
	// @param inci: a reference of int pointer. 
	//              It will point to the first incide after calling.
	// @return: the number of incides
	int getIncides(int*& inci);

	// get texturs' width
	//
	// @param
	// @return: a vertor that contains all widths of texture images
	std::vector<int> getTextWidths();

	// get texturs' height
	//
	// @param
	// @return: a vertor that contains all heights of texture images
	std::vector<int> getTextHeights();

	// get texturs' number of channels
	//
	// @param
	// @return: a vertor that contains all numbers of channels of texture images
	std::vector<int> getNChannels();

	// get texturs' data
	//
	// @param
	// @return: a vertor that contains all widths of texture images
	std::vector<unsigned char*> getTextData();

protected:

	std::vector<int> vecTextWidth; // vector for width of texture(maybe multiple)
	std::vector<int> vecTextHeight; // vector for height of texture(maybe multiple)
	std::vector<int> vecTextNChannels; // vector for number of channels of texture image(maybe multiple)
	std::vector<unsigned char*> vecTextData; // texture image data(maybe multiple)

	// an interface that subclasss must override.
	// this function will read all texture images,
	// and load their width, height, number of channels by order.
	//
	// @param paths: the vector that store all texture images' paths.
	// @return: void
	virtual void setupTexture(std::vector<const char*> paths);



private:
	// array of vertexs
	float vertexs[24] = {
		-0.1f, -0.1f, -0.1f,
		0.1f, -0.1f, -0.1f,
		0.1f, 0.1f, -0.1f,
		-0.1f, 0.1f, -0.1f,
		-0.1f, -0.1f, 0.1f,
		0.1f, -0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		-0.1f, 0.1f, 0.1f,
	};

	// array of vertexs incides
	int incides[36] = {
		// front surface
		0, 1, 2,
		0, 2, 3,
		// left
		0, 4, 7,
		0, 3, 7,
		// right
		1, 5, 6,
		1, 2, 6,
		// back
		4, 5, 6,
		4, 6, 7,
		// bottom
		0, 1, 5,
		0, 4, 5,
		// top
		2, 3, 6,
		3, 6, 7,
	};

};

