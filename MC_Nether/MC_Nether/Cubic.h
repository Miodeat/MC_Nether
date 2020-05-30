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

	// get cube width
	//
	// @param
	// @return: a float shows cube width
	float getCubeWidth();
protected:

	std::vector<int> vecTextWidth; // vector for width of texture(maybe multiple)
	std::vector<int> vecTextHeight; // vector for height of texture(maybe multiple)
	std::vector<int> vecTextNChannels; // vector for number of channels of texture image(maybe multiple)
	std::vector<unsigned char*> vecTextData; // texture image data(maybe multiple)

	// an interface that subclasss could override.
	// this function will read all texture images,
	// and load their width, height, number of channels by order.
	//
	// @param paths: the vector that store all texture images' paths.
	// @return: void
	virtual void setupTexture(std::vector<const char*> paths);



private:
	static const int verLen = 108;

	// cube width
	float halfCubeWidth = 0.05f;

	// array of vertexs
	float vertexs[verLen] = {
		// back
		-halfCubeWidth, -halfCubeWidth, -halfCubeWidth, // 0 back, lower left corner
		halfCubeWidth, -halfCubeWidth, -halfCubeWidth,  // 1 back, lower right corner
		halfCubeWidth, halfCubeWidth, -halfCubeWidth,   // 2 back, upper right corner
		halfCubeWidth, halfCubeWidth, -halfCubeWidth,   // 2 back, upper right corner
		-halfCubeWidth, halfCubeWidth, -halfCubeWidth,  // 3 back, upper left corner
		-halfCubeWidth, -halfCubeWidth, -halfCubeWidth, // 0 back, lower left corner
		// front
		-halfCubeWidth, -halfCubeWidth, halfCubeWidth,  // 4 front, lower left corner
		halfCubeWidth, -halfCubeWidth, halfCubeWidth,   // 5 front, lower right corner
		halfCubeWidth, halfCubeWidth, halfCubeWidth,    // 6 front, upper right corner
		halfCubeWidth, halfCubeWidth, halfCubeWidth,    // 6 front, upper right corner
		-halfCubeWidth, halfCubeWidth, halfCubeWidth,   // 7 front, upper left corner
		-halfCubeWidth, -halfCubeWidth, halfCubeWidth,  // 4 front, lower left corner
		// left
		-halfCubeWidth, -halfCubeWidth, halfCubeWidth,  // 4 front, lower left corner
		-halfCubeWidth, -halfCubeWidth, -halfCubeWidth, // 0 back, lower left corner
		-halfCubeWidth, halfCubeWidth, -halfCubeWidth,  // 3 back, upper left corner
		-halfCubeWidth, halfCubeWidth, -halfCubeWidth,  // 3 back, upper left corner
		-halfCubeWidth, halfCubeWidth, halfCubeWidth,   // 7 front, upper left corner
		-halfCubeWidth, -halfCubeWidth, halfCubeWidth,  // 4 front, lower left corner
		// right
		halfCubeWidth, -halfCubeWidth, -halfCubeWidth,  // 1 back, lower right corner
		halfCubeWidth, -halfCubeWidth, halfCubeWidth,   // 5 front, lower right corner
		halfCubeWidth, halfCubeWidth, halfCubeWidth,    // 6 front, upper right corner
		halfCubeWidth, halfCubeWidth, halfCubeWidth,    // 6 front, upper right corner
		halfCubeWidth, halfCubeWidth, -halfCubeWidth,   // 2 back, upper right corner
		halfCubeWidth, -halfCubeWidth, -halfCubeWidth,  // 1 back, lower right corner
		// bottom
		-halfCubeWidth, -halfCubeWidth, halfCubeWidth,  // 4 front, lower left corner
		halfCubeWidth, -halfCubeWidth, halfCubeWidth,   // 5 front, lower right corner
		halfCubeWidth, -halfCubeWidth, -halfCubeWidth,  // 1 back, lower right corner
		halfCubeWidth, -halfCubeWidth, -halfCubeWidth,  // 1 back, lower right corner
		-halfCubeWidth, -halfCubeWidth, -halfCubeWidth, // 0 back, lower left corner
		-halfCubeWidth, -halfCubeWidth, halfCubeWidth,  // 4 front, lower left corner
		// top
		-halfCubeWidth, halfCubeWidth, -halfCubeWidth,  // 3 back, upper left corner
		halfCubeWidth, halfCubeWidth, -halfCubeWidth,   // 2 back, upper right corner
		halfCubeWidth, halfCubeWidth, halfCubeWidth,    // 6 front, upper right corner
		halfCubeWidth, halfCubeWidth, halfCubeWidth,    // 6 front, upper right corner
		-halfCubeWidth, halfCubeWidth, halfCubeWidth,   // 7 front, upper left corner
		-halfCubeWidth, halfCubeWidth, -halfCubeWidth,  // 3 back, upper left corner
	};


};

