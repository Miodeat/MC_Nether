#pragma once
#include "Cubic.h"


// soul sand cube.
class SoulSand :
	public Cubic
{
private:
	float textCoor[16] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
	};

public:
	SoulSand();

	// get texture coordinates and the length of the coordinates array
	//
	// @param 
	// @return: the length of coordinates array
	int getTextCoors(float* &textC);
};

