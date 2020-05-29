#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

extern bool wPress;
extern bool sPress;
extern bool aPress;
extern bool dPress;

// keyboard callback for GLFW
// tell openGL what to do when a key is pressed
//
// @param window: a pointer to current window
//        key: tell which key is pressed
//        scancode: key scan code information
//        action: how the key is pressed(press, release, repeat)
//        mods: show assistance key is pressed or not
extern void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

