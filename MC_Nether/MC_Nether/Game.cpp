#include "Game.h"

void Game::setTexture(unsigned char* data, int width, int height, int nChannels, int index)
{
	glBindTexture(GL_TEXTURE_2D, texture[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
}

void Game::setVertex()
{
	// get vertexs and number of vertexs
	SoulSand soul;
	int cubeVerLen = soul.getVerLen();
	float* vertexs = new float[cubeVerLen];
	soul.getVertex(vertexs);

	// get soul sand texture coordinates
	int textCoorLen = soul.getTextCoorLen();
	float* textCoors = new float[textCoorLen];
	soul.getTextCoors(textCoors);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, cubeVerLen * sizeof(float) + textCoorLen * sizeof(float), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, cubeVerLen * sizeof(float), vertexs);
	glBufferSubData(GL_ARRAY_BUFFER, cubeVerLen * sizeof(float), textCoorLen * sizeof(float), textCoors);


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(cubeVerLen * sizeof(float)));
	glEnableVertexAttribArray(1);


	delete[] vertexs;
	delete[] textCoors;
}

void Game::setVertex(unsigned int &VBO, unsigned int &VAO, Cubic* cube, int cubeType)
{
	int cubeVerLen;
	float* vertexs = NULL;

	int textCoorLen;
	float* textCoors = NULL;

	
	switch (cubeType)
	{
	case GOLD_ORE: {
		GoldOre* gold = (GoldOre*)cube;

		cubeVerLen = gold->getVerLen();
		vertexs = new float[cubeVerLen];
		gold->getVertex(vertexs);

		textCoorLen = gold->getTextCoorLen();
		textCoors = new float[textCoorLen];
		gold->getTextCoors(textCoors);


		break;
	}
	case DIAMOND_ORE: {
		DiamondOre* diamond = (DiamondOre*)cube;

		cubeVerLen = diamond->getVerLen();
		vertexs = new float[cubeVerLen];
		diamond->getVertex(vertexs);

		textCoorLen = diamond->getTextCoorLen();
		textCoors = new float[textCoorLen];
		diamond->getTextCoors(textCoors);

		break;
	}
	case SAND: {
		Sand* sand = (Sand*)cube;

		cubeVerLen = sand->getVerLen();
		vertexs = new float[cubeVerLen];
		sand->getVertex(vertexs);

		textCoorLen = sand->getTextCoorLen();
		textCoors = new float[textCoorLen];
		sand->getTextCoors(textCoors);


		break;
	}
	case SOUL_SAND: {
		SoulSand* soul = (SoulSand*)cube;

		cubeVerLen = soul->getVerLen();
		vertexs = new float[cubeVerLen];
		soul->getVertex(vertexs);

		textCoorLen = soul->getTextCoorLen();
		textCoors = new float[textCoorLen];
		soul->getTextCoors(textCoors);


		break;
	}
	case NETHER_BRICK: {
		NetherBrick* nBrick = (NetherBrick*)cube;

		cubeVerLen = nBrick->getVerLen();
		vertexs = new float[cubeVerLen];
		nBrick->getVertex(vertexs);

		textCoorLen = nBrick->getTextCoorLen();
		textCoors = new float[textCoorLen];
		nBrick->getTextCoors(textCoors);

		break;
	}
	case NETHER_RACK: {
		NetherRack* nRack = (NetherRack*)cube;

		cubeVerLen = nRack->getVerLen();
		vertexs = new float[cubeVerLen];
		nRack->getVertex(vertexs);

		textCoorLen = nRack->getTextCoorLen();
		textCoors = new float[textCoorLen];
		nRack->getTextCoors(textCoors);

		break;
	}
	default:
		exit(0);
	}

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, cubeVerLen * sizeof(float) + textCoorLen * sizeof(float), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, cubeVerLen * sizeof(float), vertexs);
	glBufferSubData(GL_ARRAY_BUFFER, cubeVerLen * sizeof(float), textCoorLen * sizeof(float), textCoors);


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(cubeVerLen * sizeof(float)));
	glEnableVertexAttribArray(1);


	delete[] vertexs;
	delete[] textCoors;
}

void Game::setShader(const char* vs, const char* fs)
{
	pCubeShader = new Shader(vs, fs);
}

void Game::drawCube(int textIndex, float x, float y, float z)
{
	if (textIndex < 0) {
		return;
	}

	// calculate model changing
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(x, y, z));
	pCubeShader->setMat4("model", model);
	// calculate view changing
	glm::mat4 view;
	view = glm::lookAt(lookPos, lookPos + lookFront, lookUp);
	pCubeShader->setMat4("view", view);
	// calculate projectin changing
	glm::mat4 projection = glm::perspective(fov * 0.5 * glm::pi<double>() / 360.0, aspect, zNear, zFar);
	pCubeShader->setMat4("projection", projection);

	pCubeShader->setInt("texture", textIndex);

	// do rendering
	// draw cube
	glBindTexture(GL_TEXTURE_2D, texture[textIndex]);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Game::keyPress()
{
	if (wPress) {
		lookPos += keySpeed * lookFront;
		wPress = false;
	}
	if (sPress) {
		lookPos -= keySpeed * lookFront;
		sPress = false;
	}
	if (aPress) {
		lookPos += keySpeed * lookRight;
		aPress = false;
	}
	if (dPress) {
		lookPos -= keySpeed * lookRight;
		dPress = false;
	}
}

void Game::destory()
{
	if (pCubeShader != NULL) {
		delete pCubeShader;
	}

	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteTextures(6, texture);
}

void Game::render()
{
	// clear screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// use the shader program
	pCubeShader->use();

	// update lookfront param
	lookFront = glm::normalize(front);

	// update lookRight
	lookRight = glm::normalize(glm::cross(lookUp, lookFront));
	keyPress();


	SimplexNoise sNoise;

	for (float z = worldZmin; z < worldZmax; z += 0.4) {	
		for (float y = worldYmin; y < worldYmax; y += 0.4) {
			for (float x = worldXmin; x < worldXmax; x += 0.4) {
				if ((z > lookPos[2] - 1.0f && z < lookPos[2] + 0.4) 
					&& (y < lookPos[1] + 1.0f && y > lookPos[1]) 
					&& (x > lookPos[0] - 1.0f && x < lookPos[0] + 1.0f)) {
					continue;
				}
				float noiseValue = sNoise.noise(z, y, x) + 1;
				noiseValue *= 3.5f;
				int textIndex = (int)floor(noiseValue) - 1;
				if (textIndex == 6) {
					textIndex = -1;
				}

				drawCube(textIndex, x, y, z);
			}
		}
	}

}

Game::Game(int windowWid, int winHei)
{
	this->winWidth = windowWid;
	this->winHeight = winHei;

	aspect = winWidth / (double)winHeight;

	setVertex();

	setShader("CubeShader.vs", "CubeShader.fsh");
	
	GoldOre gold;
	DiamondOre diamond;
	Sand sand;
	SoulSand soul;
	NetherBrick nBrick;
	NetherRack nRack;

	// set texture parameters
	glGenTextures(textureNum, texture);

	setTexture(gold.getTextData().at(0), gold.getTextWidths().at(0), 
		gold.getTextHeights().at(0), gold.getNChannels().at(0), 0);

	setTexture(diamond.getTextData().at(0), diamond.getTextWidths().at(0),
		diamond.getTextHeights().at(0), diamond.getNChannels().at(0), 1);

	setTexture(sand.getTextData().at(0), sand.getTextWidths().at(0),
		sand.getTextHeights().at(0), sand.getNChannels().at(0), 2);

	setTexture(soul.getTextData().at(0), soul.getTextWidths().at(0),
		soul.getTextHeights().at(0), soul.getNChannels().at(0), 3);

	setTexture(nBrick.getTextData().at(0), nBrick.getTextWidths().at(0),
		nBrick.getTextHeights().at(0), nBrick.getNChannels().at(0), 4);

	setTexture(nRack.getTextData().at(0), nRack.getTextWidths().at(0),
		nRack.getTextHeights().at(0), nRack.getNChannels().at(0), 5);

	// enable 2D texture
	glEnable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, texture[5]);

}
