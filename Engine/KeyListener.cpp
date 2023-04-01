#include "KeyListener.h"
#include<GLFW/glfw3.h>

KeyListener* KeyListener::get()
{
	if (instance == NULL) {
		instance = new KeyListener();
	}

	return instance;
}

KeyListener::KeyListener() {

}

void KeyListener::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		get()->keyPressed[key] = true;
	}
	else if (action == GLFW_RELEASE) {
		get()->keyPressed[key] = false;
	}
}

bool KeyListener::isKeyPressed(int key)
{
	return get()->keyPressed[key];
}


