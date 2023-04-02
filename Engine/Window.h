#pragma once

#include <iostream>
#include "Scene.h"
#include <GLFW/glfw3.h>

class Window {
public:
	static Window* get();
	static void cangeScene(int newScene);
	void run();
private:
	void init();
	void loop();

	//Member
	static Scene* currentScene;
	int width, height;
	const char* title;
	GLFWwindow* glfwWindow;
	static inline Window* instance = NULL;
	Window();
};
