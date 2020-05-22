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
	// @return: void
	void getVertex(float*& ver);

	// get the length of vertexs array, A.K.A. number of vertexs
	//
	// @param
	// @return: the length of vertexs array
	int getVerLen();

	// get incides array
	//
	// @param inci: a reference of int pointer. 
	//              It will point to the first incide after calling.
	// @return: void
	void getIncides(unsigned int*& inci);

	// get the length of incides array
	//
	// @param
	// @return: the length of incides array
	int getIncidesLen();

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
	static const int verLen = 24;

	// array of vertexs
	float vertexs[verLen] = {
		-0.2f, -0.2f, -0.2f, // 0 front, lower left corner
		0.2f, -0.2f, -0.2f,  // 1 front, lower right corner
		0.2f, 0.2f, -0.2f,   // 2 front, upper right corner
		-0.2f, 0.2f, -0.2f,  // 3 front, upper left corner
		-0.2f, -0.2f, 0.2f,  // 4 back, lower left corner
		0.2f, -0.2f, 0.2f,   // 5 back, lower right corner
		0.2f, 0.2f, 0.2f,    // 6 back, upper right corner
		-0.2f, 0.2f, 0.2f,   // 7 back, upper left corner
	};

	static const int inciLen = 36;

	// array of vertexs incides
	unsigned int incides[inciLen] = {
		// front surface
		2, 1, 0,
		0, 3, 2,
		// left
		3, 0, 4,
		4, 7, 3,
		// right
		6, 5, 1,
		1, 2, 6,
		// back
		7, 4, 5,
		5, 6, 7,
		// bottom
		1, 5, 4,
		4, 0, 1,
		// top
		6, 2, 3,
		3, 7, 6,
	};

};

