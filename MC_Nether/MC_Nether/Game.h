#pragma once
#include <iostream>
#include <math.h>

#include "Mouse.h"
#include "Keyboard.h"

#include "Chunk.h"

class Game
{
private:
	const static int cubicTypeNum = 6; // number of different cubic
	const static int textureNum = 6; // number of textures 

	const static int NONE = -1;        // do not draw cube
	const static int GOLD_ORE = 0;     // id and index in array "textureNum" of gold_ore
	const static int DIAMOND_ORE = 1;  // id and index of diamond_ore
	const static int SAND = 2;         // id and index of sand
	const static int SOUL_SAND = 3;    // id and index of soul_sand
	const static int NETHER_BRICK = 4; // id and index of nether_brick
	const static int NETHER_RACK = 5;  // id and index of nether_rack

	int winWidth, winHeight; // window's width and height

	float worldZmin = -5.f;
	float worldZmax = 5.f;
	float worldXmin = -5.f;
	float worldXmax = 5.f;
	float worldYmin = -5.f;
	float worldYmax = 5.f;

	unsigned int texture[textureNum]; // array stroes textures

	unsigned int VBO; // vertex buffer
	unsigned int VAO; // vertex array

	unsigned int EBO; // incides buffer

	Shader* pCubeShader = NULL; // shader for cubes

	glm::vec3 lookPos = glm::vec3(0.0f, 0.0f, 10.f);  // camera's position
	glm::vec3 lookFront = glm::vec3(0.0f, 0.0f, -1.0f); // camera's front direction
	glm::vec3 lookUp = glm::vec3(0.0f, 1.0f, 0.0f); // define the direction "up" for the world
	glm::vec3 lookRight = glm::normalize(glm::cross(lookUp, lookFront)); // camera's right direction

	double aspect; // view port's aspect ratio
	double fov = 45;
	double zNear = 0.01;
	double zFar = 100.0;

	std::vector<Chunk> chunks; // a vector stores all chunks

	float cameraToFoot = 0.25f;
	float cameraToTop = 0.05f;
	float cameraWid = 0.1f;
	boundary cameraBoun;

	float keySpeed = 0.1f; // how fast camera move when key is pressed.

	// get texture and bind to openGL
	//
	// @param
	// @return: void
	void setTexture(unsigned char* data,int width, int height, int nChannels, int index);

	// generate and bind vertex buffer obejects and vertex array objects
	// tell openGL how to draw the vertexs
	// 
	// @param
	// @return: void
	void setVertex();
	
	void setVertex(unsigned int &VBO, unsigned int &VAO, Cubic* cube, int cubeType);

	void setShader(const char* vs, const char* fs);

	void drawCube(int textIndex, float x, float y, float z);

	void createChunk();

	void drawChunk();

	bool checkMoveCollision(glm::vec3 target);

	bool checkCubeCollision(int chunkIndex, boundary boun);

	boundary genCameraBoun(glm::vec3 target);

public:
	Game(int windowWid, int windowHei);

	// render function
	//
	// @param
	// @return: void
	void render();

	// update camera position, depending on keyboard
	//
	// @param
	// @return: void
	void keyPress();

	void mouseClick();

	void destory();
};

