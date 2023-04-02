#pragma once
#include <iostream>

#include <GLFW/glfw3.h>

class KeyListener {
public:
	static KeyListener* get();
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static bool isKeyPressed(int key);
	bool keyPressed[356];
private:
	static inline KeyListener* instance = NULL;
	KeyListener();
};