#include "KeyListener.h"

KeyListener* KeyListener::get()
{
	if (instance == NULL) {
		instance = new KeyListener();
	}

	return instance;
}

KeyListener::KeyListener() {
	for (int i = 0; i < 356; i++) {
		keyPressed[i] = false;
	}
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


