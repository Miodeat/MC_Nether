#pragma once

// every cube should inherit this class
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

protected:
	// an interface that subclasss must override.
	virtual void setupTexture() = 0;

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

