#include "MouseListener.h"


MouseListener* MouseListener::get()
{
	if (instance == NULL) {
		instance = new MouseListener();
	}

	return instance;

}

void MouseListener::mousePosCallback(GLFWwindow* window, double xpos, double ypos)
{
	get()->lastX = get()->xPos;
	get()->lastY = get()->yPos;
	get()->xPos = xpos;
	get()->yPos = ypos;
	get()->isdragging = get()->mouseButtonPressed[1] || get()->mouseButtonPressed[2] || get()->mouseButtonPressed[3];


}

void MouseListener::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS) {
		get()->mouseButtonPressed[button] = true;
	}
	else if (action == GLFW_RELEASE) {
		get()->mouseButtonPressed[button] = false;
		get()->isdragging = false;
	}
}

void MouseListener::mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
	get()->scrollX = xOffset;
	get()->scrollY = yOffset;
}

void MouseListener::endFrame()
{
	get()->scrollX = 0;
	get()->scrollY = 0;
	get()->lastX = get()->xPos;
	get()->lastY = get()->yPos;


}

float MouseListener::getX()
{
	return (float) get()->xPos;
}

float MouseListener::getY()
{
	return (float)get()->yPos;
}

float MouseListener::getDx()
{
	return (float)(get()->lastX - get()->xPos);
}

float MouseListener::getDy()
{
	return (float)(get()->lastY - get()->yPos);
}

float MouseListener::getScrollX()
{
	return (float)get()->scrollX;
}

float MouseListener::getScrollY()
{
	return (float)get()->scrollY;
}

bool MouseListener::isDragging() {
	return get()->isdragging;
}

bool MouseListener::mouseButtonDown(int button)
{
	return get()->mouseButtonPressed[button];
}




MouseListener::MouseListener() {
	scrollX, scrollY, xPos, yPos, lastX, lastY = 0, 0, 0, 0, 0, 0;
	for (int i = 0; i < 3; i++) {
		mouseButtonPressed[i] = false;
	}
}
