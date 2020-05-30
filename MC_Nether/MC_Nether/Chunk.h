#pragma once
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <learnopengl/shader.h>
#include <time.h>
#include <stdlib.h>

#include "SimplexNoise.h"
#include "SoulSand.h"
#include "GoldOre.h"
#include "DiamondOre.h"
#include "NetherBrick.h"
#include "NetherRack.h"
#include "Sand.h"


class Chunk
{
private:
	const static int NONE = -1;        // do not draw cube
	const static int GOLD_ORE = 0;     // id and index in array "textureNum" of gold_ore
	const static int DIAMOND_ORE = 1;  // id and index of diamond_ore
	const static int SAND = 2;         // id and index of sand
	const static int SOUL_SAND = 3;    // id and index of soul_sand
	const static int NETHER_BRICK = 4; // id and index of nether_brick
	const static int NETHER_RACK = 5;  // id and index of nether_rack

	glm::vec3 offset0;
	glm::vec3 offset1;
	glm::vec3 offset2;

	int GenerateBlockType(glm::vec3 pos);
	int GenHeight(glm::vec3 pos);

	
public:
	const static int width = 30;
	const static int height = 80;
	
	float baseHeight = 10.f;
	float frequency = 0.025f;
	float amplitude = 5;

	float blockWid;

	int map[width][height][width];

	glm::vec3 transPos;

	Chunk();
	Chunk(glm::vec3 trans);

	void initMap();
};