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

	int cubeNorLen = soul.getNorLen();
	float* normals = new float[cubeNorLen];
	soul.getNormal(normals);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 
		cubeVerLen * sizeof(float) + textCoorLen * sizeof(float) + cubeNorLen * sizeof(float),
		NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, cubeVerLen * sizeof(float), vertexs);
	glBufferSubData(GL_ARRAY_BUFFER, cubeVerLen * sizeof(float), textCoorLen * sizeof(float), textCoors);
	glBufferSubData(GL_ARRAY_BUFFER, cubeVerLen * sizeof(float) + textCoorLen * sizeof(float),
		cubeNorLen * sizeof(float), normals);


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(cubeVerLen * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 
		(void*)(cubeVerLen * sizeof(float) + textCoorLen * sizeof(float)));
	glEnableVertexAttribArray(2);


	delete[] vertexs;
	delete[] textCoors;
	delete[] normals;
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

	pCubeShader->setVec3("lightPos", lightPos);
	pCubeShader->setVec3("lightAmbient", lightAmbient);
	pCubeShader->setVec3("lightDiffuse", lightDiffuse);
	pCubeShader->setVec3("lightSpecular", lightSpecular);
	pCubeShader->setVec3("lookPos", lookPos);
	pCubeShader->setFloat("matShininess", matShininess);

	pCubeShader->setInt("texture", textIndex);

	// do rendering
	// draw cube
	glBindTexture(GL_TEXTURE_2D, texture[textIndex]);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Game::createChunk()
{
	if (chunks.size() == 0) {
		Chunk chunk(glm::vec3(0, 0, 0));
		float blockWidth = chunk.blockWid;
		int midBlock = (chunk.width / 2) - 1;
		/*for (int i = chunk.height - 1; i >= 0; i--) {
			if (chunk.map[midBlock][i][midBlock] == NONE &&
				chunk.map[midBlock][i - 1][midBlock] == NONE &&
				chunk.map[midBlock][i - 2][midBlock] != NONE) {
				lookPos = glm::vec3(midBlock * blockWidth, i * blockWidth, midBlock * blockWidth);
				break;
			}
		}*/
		chunks.push_back(chunk);
	}
}

void Game::drawChunk()
{
	for (int i = 0; i < chunks.size(); i++) {
		Chunk chunk = chunks.at(i);
		float wid = chunk.blockWid;
		float halfWid = wid / 2;

		for (int x = 0; x < chunk.width; x++)
		{
			for (int y = 0; y < chunk.height; y++)
			{
				for (int z = 0; z < chunk.width; z++)
				{
					float opX = x * wid;
					float opY = y * wid;
					float opZ = z * wid;
					drawCube(chunk.map[x][y][z],
						opX + chunk.getTransPos().x,
						opY + chunk.getTransPos().y,
						opZ + chunk.getTransPos().z);
				}
			}
		}
	}

}

bool Game::checkMoveCollision(glm::vec3 target)
{
	boundary tarBoun = genCameraBoun(target);
	int chunkIndex = -1;
	for (int i = 0; i < chunks.size(); i++) {
		boundary chunkBoun = chunks.at(i).boun;
		if (tarBoun.minx <= chunkBoun.maxx && tarBoun.maxx >= chunkBoun.minx &&
			tarBoun.miny <= chunkBoun.maxy && tarBoun.maxy >= chunkBoun.miny &&
			tarBoun.minz <= chunkBoun.maxz && tarBoun.maxz >= chunkBoun.minz) {
			chunkIndex = i;
			break;
		}
	}

	if (chunkIndex == -1) {
		return false;
	}
	
	return checkCubeCollision(chunkIndex, tarBoun);

}

bool Game::checkCubeCollision(int chunkIndex, boundary bound)
{
	Chunk chunk = chunks.at(chunkIndex);
	for (int x = 0; x < chunk.width; x++)
	{
		for (int y = 0; y < chunk.height; y++)
		{
			for (int z = 0; z < chunk.width; z++)
			{
				boundary cubeB = chunk.cubeBouns[x][y][z];
				int type = chunk.map[x][y][z];
				if (type == NONE) {
					continue;
				}
				if (bound.minx < cubeB.maxx && bound.maxx > cubeB.minx &&
					bound.miny < cubeB.maxy && bound.maxy > cubeB.miny &&
					bound.minz < cubeB.maxz && bound.maxz > cubeB.minz) {
					return true;
				}
			}
		}
	}
	return false;
}

boundary Game::genCameraBoun(glm::vec3 target)
{
	return boundary(target.x - cameraWid, target.x + cameraWid,
		target.y - cameraToFoot, target.y + cameraToTop,
		target.z - cameraWid, target.z + cameraWid);
}

std::vector<glm::vec3> Game::getCubeCanChoose()
{
	std::vector<glm::vec3> result;
	Chunk chunk = chunks.at(0);
	for (int x = 0; x < chunk.width; x++)
	{
		for (int y = 0; y < chunk.height; y++)
		{
			for (int z = 0; z < chunk.width; z++)
			{
				glm::vec3 worldC = chunk.worldCoor[x][y][z];
				if (abs(worldC.x - lookPos.x) <= 1.0f &&
					abs(worldC.y - lookPos.y) <= 2.0f &&
					abs(worldC.z - lookPos.z) <= 2.0f) {
					result.push_back(glm::vec3(x, y, z));
				}
			}
		}
	}
	return result;
}

bool Game::rayAABB(boundary boun)
{

	glm::vec3 ptOnPlane; //射线与包围盒某面的交点
	glm::vec3 min = glm::vec3(boun.minx, boun.miny, boun.minz); //aabb包围盒最小点坐标
	glm::vec3 max = glm::vec3(boun.maxx, boun.maxy, boun.maxz); //aabb包围盒最大点坐标

	const glm::vec3& origin = lookPos; //射线起始点
	const glm::vec3& dir = lookFront; //方向矢量

	float t;

	//分别判断射线与各面的相交情况

	//判断射线与包围盒x轴方向的面是否有交点
	if (dir.x != 0.f) //射线x轴方向分量不为0 若射线方向矢量的x轴分量为0，射线不可能经过包围盒朝x轴方向的两个面
	{
		/*
		  使用射线与平面相交的公式求交点
		 */
		if (dir.x > 0)//若射线沿x轴正方向偏移
			t = (min.x - origin.x) / dir.x;
		else  //射线沿x轴负方向偏移
			t = (max.x - origin.x) / dir.x;

		if (t > 0.f) //t>0时则射线与平面相交
		{
			ptOnPlane = origin + t * dir; //计算交点坐标
			//判断交点是否在当前面内
			if (min.y < ptOnPlane.y && ptOnPlane.y < max.y && min.z < ptOnPlane.z && ptOnPlane.z < max.z)
			{
				return true; //射线与包围盒有交点
			}
		}
	}

	//若射线沿y轴方向有分量 判断是否与包围盒y轴方向有交点
	if (dir.y != 0.f)
	{
		if (dir.y > 0)
			t = (min.y - origin.y) / dir.y;
		else
			t = (max.y - origin.y) / dir.y;

		if (t > 0.f)
		{
			ptOnPlane = origin + t * dir;

			if (min.z < ptOnPlane.z && ptOnPlane.z < max.z && min.x < ptOnPlane.x && ptOnPlane.x < max.x)
			{
				return true;
			}
		}
	}

	//若射线沿z轴方向有分量 判断是否与包围盒y轴方向有交点
	if (dir.z != 0.f)
	{
		if (dir.z > 0)
			t = (min.z - origin.z) / dir.z;
		else
			t = (max.z - origin.z) / dir.z;

		if (t > 0.f)
		{
			ptOnPlane = origin + t * dir;

			if (min.x < ptOnPlane.x && ptOnPlane.x < max.x && min.y < ptOnPlane.y && ptOnPlane.y < max.y)
			{
				return true;
			}
		}
	}
	return false;
}

void Game::keyPress()
{
	glm::vec3 front = lookFront;
	front.y = 0.0f;
	if (wPress) {
		glm::vec3 targetPos = lookPos + (keySpeed * front);
		if (!checkMoveCollision(targetPos)) {
			lookPos = targetPos;
			lightPos = targetPos;
		}
		wPress = false;
	}
	if (sPress) {
		glm::vec3 targetPos = lookPos - (keySpeed * front);
		if (!checkMoveCollision(targetPos)) {
			lookPos = targetPos;
			lightPos = targetPos;
		}
		sPress = false;
	}
	if (aPress) {
		glm::vec3 targetPos = lookPos + (keySpeed * lookRight);
		if (!checkMoveCollision(targetPos)) {
			lookPos = targetPos;
			lightPos = targetPos;
		}
		aPress = false;
	}
	if (dPress) {
		glm::vec3 targetPos = lookPos - (keySpeed * lookRight);
		if (!checkMoveCollision(targetPos)) {
			lookPos = targetPos;
			lightPos = targetPos;
		}
		dPress = false;
	}

	if (spacePress) {
		glm::vec3 targetPos = lookPos + (keySpeed * lookUp);
		if (!checkMoveCollision(targetPos)) {
			lookPos = targetPos;
			lightPos = targetPos;
		}
		spacePress = false;
	}

	if (LCtrlPress) {
		glm::vec3 targetPos = lookPos - (keySpeed * lookUp);
		if (!checkMoveCollision(targetPos)) {
			lookPos = targetPos;
			lightPos = targetPos;
		}
		LCtrlPress = false;
	}
}

void Game::mouseClick()
{
	if (mouseBtnLeft) {
		std::vector<glm::vec3> chooseCubePos = getCubeCanChoose();
		mouseBtnLeft = false;
	}

	if (mouseBtnRight) {
		std::vector<glm::vec3> chooseCubePos = getCubeCanChoose();
		for (int i = 0; i < chooseCubePos.size(); i++) {
			glm::vec3 tmp = chooseCubePos.at(i);
			
		}
		mouseBtnRight = false;
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
	glClearColor(0.3f, 0.0f, 0.0f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// use the shader program
	pCubeShader->use();

	// update lookfront param
	lookFront = glm::normalize(front);

	// update lookRight
	lookRight = glm::normalize(glm::cross(lookUp, lookFront));
	keyPress();
	drawChunk();

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

	createChunk();
	cameraBoun = genCameraBoun(lookPos);
}
