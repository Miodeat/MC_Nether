#include "WindowSize.h"

int winWidth = 800, winHeight = 800; // window's width and height
bool windowSizeChange = false;
double asp = winWidth / (double)winHeight;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	windowSizeChange = true;
	asp = height > 0 ? width / (double)height : 1.0;
	glViewport(0, 0, width, height);
}