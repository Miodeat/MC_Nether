#pragma once
#include "Cubic.h"


// soul sand cube.
class SoulSand :
	public Cubic
{
private:
	static const int textCoorLen = 16;
	float textCoor[textCoorLen] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		//// front
		//1.0f, 1.0f,
		//1.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 1.0f,
		//1.0f, 1.0f,
		//// left
		//1.0f, 1.0f,
		//1.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 1.0f,
		//1.0f, 1.0f,
		//// right
		//1.0f, 1.0f,
		//1.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 1.0f,
		//1.0f, 1.0f,
		//// back
		//1.0f, 1.0f,
		//1.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 1.0f,
		//1.0f, 1.0f,
		//// bottom
		//1.0f, 1.0f,
		//1.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 1.0f,
		//1.0f, 1.0f,
		//// top
		//1.0f, 1.0f,
		//1.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 0.0f,
		//0.0f, 1.0f,
		//1.0f, 1.0f
	};

public:
	SoulSand();

	// get texture coordinates and the length of the coordinates array
	//
	// @param 
	// @return: void
	void getTextCoors(float* &textC);

	// get the length of texture coordinates array
	//
	// @param:
	// @return: the length of texture coordinates array
	int getTextCoorLen();
};

