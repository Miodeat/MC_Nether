#include "Keyboard.h"

bool wPress = false;
bool sPress = false;
bool aPress = false;
bool dPress = false;
bool spacePress = false;
bool LCtrlPress = false;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		switch (key)
		{
		case GLFW_KEY_W:
			wPress = true;
			break;
		case GLFW_KEY_S:
			sPress = true;
			break;
		case GLFW_KEY_A:
			aPress = true;
			break;
		case GLFW_KEY_D:
			dPress = true;
			break;
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, true);
			break;
		case GLFW_KEY_SPACE:
			spacePress = true;
			break;
		case GLFW_KEY_LEFT_CONTROL:
			LCtrlPress = true;
			break;
		default:
			break;
		}
	}
}
