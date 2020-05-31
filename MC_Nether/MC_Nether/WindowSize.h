#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// window's width and height
extern int winWidth;
extern int winHeight; 
extern bool windowSizeChange;
extern double asp;

// a callback function that will be called when size of window was changed
//
// @param window: a pointer point to the window, of which the size was changed.
//        width: the width of window, after changing.
//        height: the height of window, after changing.
// @return
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);