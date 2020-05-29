#include "Mouse.h"

double lastX; // last x position of cursor
double lastY; // last y position of cursor

float yaw = 0.0f; // redeclare xTrans and initialize
float pitch = 0.0f; // redeclare yTrans and initialize

glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f); // redeclare

bool isMouseInit = false; // tell whether the lastX and lastY has been initialize

float moveSensitivity = 0.05f; // the mouse's move sensitivity

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	// initialize lastX and lastY
	if (!isMouseInit) {
		lastX = xpos;
		lastY = ypos;
		isMouseInit = true;
		return;
	}

	// calculate cursor moving distance
	float dx = xpos - lastX;
	float dy = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	dx *= moveSensitivity;
	dy *= moveSensitivity;

	// calculate moving 

	yaw += dx;
	pitch += dy;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	front.x = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = -cos(glm::radians(yaw)) * cos(glm::radians(pitch));
}
