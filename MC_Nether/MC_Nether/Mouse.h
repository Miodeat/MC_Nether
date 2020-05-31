#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


extern float yaw; // the distance that cursor moved along x axis
extern float pitch; // the distance that cursor moved along y axis

extern glm::vec3 front; // the direction camera should look at

extern bool mouseBtnLeft;
extern bool mouseBtnRight;

// a callback function for openGL, 
// tell it what to do when a mouse button is pressed.
// 
// @param window: a pointer point to the openGL window
//        btn: a int param shows which botton is pressed
//        action: a int param shows which action(press,click...) user did
//        mods: show assistance key is pressed or not
// @return: void
extern void mouseBtnCallback(GLFWwindow* window, int btn, int action, int mods);

// a callback function for openGL,
// tell it what to da when mouse is moving.
//
// @param window: a pointer point to the openGL window
//        xpos: cursor's x coordinate
//        ypos: cursor's y coordinate
// @return: void
extern void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);


