#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

class Window {
public:
	Window();
	void run();
	
private:
	void init();
	void loop();
	int width, height;
	const char* title;
	GLFWwindow* glfwWindow;
};