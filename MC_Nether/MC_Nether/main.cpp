#include "Game.h"

int winWidth = 800, winHeight = 800; // window's width and height

//const int textureNum = 1; // number of textures 
//unsigned int texture[textureNum]; // array stroes textures
//
//unsigned int VBO; // vertex buffer
//unsigned int VAO; // vertex array
//
//unsigned int EBO; // incides buffer
//
//Shader* pCubeShader = NULL; // shader for cubes
//
//
//glm::vec3 lookPos = glm::vec3(0.0f, 0.0f, 10.0f);  // camera's position
//glm::vec3 lookFront = glm::vec3(0.0f, 0.0f, -1.0f); // camera's front direction
//glm::vec3 lookUp = glm::vec3(0.0f, 1.0f, 0.0f); // define the direction "up" for the world
//glm::vec3 lookRight = glm::normalize(glm::cross(lookUp, lookFront)); // camera's right direction
//
//double aspect = winWidth / (double)winHeight; // view port's aspect ratio
//double fov = 45;
//double zNear = 0.01;
//double zFar = 100.0;
//
//float keySpeed = 0.1f; // how fast camera move when key is pressed.



// generate and bind vertex buffer obejects and vertex array objects
// tell openGL how to draw the vertexs
// 
// @param
// @return: void
//void setup_vertexs() 
//{
//	// get soul sand vertexs and number of vertexs
//	SoulSand soul;
//	int cubeVerLen = soul.getVerLen();
//	float* vertexs = new float[cubeVerLen];
//	soul.getVertex(vertexs);
//
//	// get soul sand texture coordinates
//	int textCoorLen = soul.getTextCoorLen();
//	float* textCoors = new float[textCoorLen];
//	soul.getTextCoors(textCoors);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, cubeVerLen * sizeof(float) + textCoorLen * sizeof(float), NULL, GL_STATIC_DRAW);
//	glBufferSubData(GL_ARRAY_BUFFER, 0, cubeVerLen * sizeof(float), vertexs);
//	glBufferSubData(GL_ARRAY_BUFFER, cubeVerLen * sizeof(float), textCoorLen * sizeof(float), textCoors);
//
//
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(cubeVerLen * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	int incidesLen = soul.getIncidesLen();
//	unsigned int* incides = new unsigned int[incidesLen];
//	soul.getIncides(incides);
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, incidesLen * sizeof(unsigned int), incides, GL_STATIC_DRAW);
//
//	delete[] vertexs;
//	delete[] textCoors;
//	delete[] incides;
//}
//
//// set the vertex shader and fragment shader by using "learnopengl/shader.h"
////
//// @param
//// @return: void
//void setup_shader() {
//	pCubeShader = new Shader("CubeShader.vs", "CubeShader.fsh");
//
//	pCubeShader->setInt("texture", 0);
//}
//
//// get texture and bind to openGL
//void set_texture() {
//	// get soul sand texture
//	SoulSand soul;
//	unsigned char* data = soul.getTextData().at(0);
//	
//	int width = soul.getTextWidths().at(0);
//	int height = soul.getTextHeights().at(0);
//	int nChannels = soul.getNChannels().at(0);
//	
//
//	// set texture parameters
//	glGenTextures(textureNum, texture);
//	glBindTexture(GL_TEXTURE_2D, texture[0]);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//	stbi_image_free(data);
//
//	// enable 2D texture
//	glEnable(GL_TEXTURE_2D);
//	glActiveTexture(GL_TEXTURE0);
//
//	// enabling depth test
//	glEnable(GL_DEPTH_TEST);
//}
//
//// render function
////
//// @param
//// @return: void
//void render() {
//	// clear screen
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	// use the shader program
//	pCubeShader->use();
//
//	// update look at param
//	lookFront[0] += lookAtXTrans;
//	lookFront[1] += lookAtYTrans;
//
//	// reset xTrans and yTrans
//	lookAtXTrans = 0.0f;
//	lookAtYTrans = 0.0f;
//
//	// calculate model changing
//	glm::mat4 model;
//	// pCubeShader->setMat4("model", model);
//	// calculate view changing
//	glm::mat4 view;
//	view = glm::lookAt(lookPos, lookPos + lookFront, lookUp);
//	pCubeShader->setMat4("view", view);
//	// calculate projectin changing
//	glm::mat4 projection = glm::perspective(fov * 0.5 * glm::pi<double>() / 360.0, aspect, zNear, zFar);
//	pCubeShader->setMat4("projection", projection);
//
//
//	// do rendering
//	// draw cube
//	glBindTexture(GL_TEXTURE_2D, texture[0]);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//}
//
//
//void destory() {
//	if (pCubeShader != NULL) {
//		delete pCubeShader;
//	}
//
//	glDeleteBuffers(1, &VBO);
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteTextures(1, texture);
//}


// a callback function that will be called when size of window was changed
//
// @param window: a pointer point to the window, of which the size was changed.
//        width: the width of window, after changing.
//        height: the height of window, after changing.
// @return
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


int main() {

	// initialize GLFW and declare the version of openGL
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create the window
	GLFWwindow* window = glfwCreateWindow(winWidth, winHeight, "MC_Nether", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// set up the context of current thread by using context of window we created
	glfwMakeContextCurrent(window);

	// initialize glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// set up view port
	glViewport(0, 0, winWidth, winHeight);

	// enabling depth test
	glEnable(GL_DEPTH_TEST);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// register the callback function of size-changing event
	glfwSetWindowSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, cursorPosCallback);
	glfwSetKeyCallback(window, keyCallback);

	//setup_vertexs();
	//setup_shader();
	//set_texture();
	Game mineNether(winHeight, winWidth);

	while (!glfwWindowShouldClose(window)) {
		//render();
		mineNether.render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//destory();
	mineNether.destory();
	glfwTerminate();
	return 0;
}

