#include "Keyboard.h"

bool wPress = false;
bool sPress = false;
bool aPress = false;
bool dPress = false;
bool spacePress = false;
bool LCtrlPress = false;

bool currentHandCubeChange = false;
int newHandCube = 6;

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
		case GLFW_KEY_1:
			currentHandCubeChange = true;
			newHandCube = 1;
			break;
		case GLFW_KEY_2:
			currentHandCubeChange = true;
			newHandCube = 2;
			break;
		case GLFW_KEY_3:
			currentHandCubeChange = true;
			newHandCube = 3;
			break;
		case GLFW_KEY_4:
			currentHandCubeChange = true;
			newHandCube = 4;
			break;
		case GLFW_KEY_5:
			currentHandCubeChange = true;
			newHandCube = 5;
			break;
		case GLFW_KEY_6:
			currentHandCubeChange = true;
			newHandCube = 6;
			break;
		default:
			break;
		}
	}
}
