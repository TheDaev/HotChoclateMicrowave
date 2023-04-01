#pragma once
#include<iostream>
#include <GLFW/glfw3.h>

class KeyListener {
public:
	static KeyListener* get();
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static bool isKeyPressed(int key);
private:
	static inline KeyListener* instance = NULL;
	bool keyPressed[356];
	KeyListener();
};