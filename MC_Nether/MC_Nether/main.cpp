#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

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
	GLFWwindow* window = glfwCreateWindow(800, 600, "MC_Nether", NULL, NULL);
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
	glViewport(0, 0, 800, 600);

	// register the callback function of size-changing event
	glfwSetWindowSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

