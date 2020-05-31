#include "Game.h"




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
	glfwSetMouseButtonCallback(window, mouseBtnCallback);
	glfwSetKeyCallback(window, keyCallback);

	//setup_vertexs();
	//setup_shader();
	//set_texture();
	Game mineNether(winWidth, winHeight);

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

