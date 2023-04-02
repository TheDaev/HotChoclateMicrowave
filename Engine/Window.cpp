#include "Window.h"


#include "MouseListener.h"
#include "KeyListener.h"
#include "LevelScene.h"
#include "LevelSceneEditor.h"


Window::Window() {
	width = 900;
	height = 450;
	title = "Window";
}

void Window::run() {
	init();
	loop();

	//Free everything
	delete MouseListener::get();
	delete KeyListener::get();

	glfwTerminate();
}

void Window::init() {
	//initialize glfw
	if (!glfwInit()) {
		std::cout << "Failed to initialized glfw" << std::endl;
	}

	//Configure glfw
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

	//creating the window
	glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (&glfwWindow == NULL) {
		std::cout << "Failed to create glfw window" << std::endl;
	}

	glfwSetCursorPosCallback(glfwWindow, MouseListener::mousePosCallback);
	glfwSetMouseButtonCallback(glfwWindow, MouseListener::mouseButtonCallback);
	glfwSetScrollCallback(glfwWindow, MouseListener::mouseScrollCallback);
	glfwSetKeyCallback(glfwWindow, KeyListener::key_callback);

	//Make open gl context current
	glfwMakeContextCurrent(glfwWindow);
	glfwSwapInterval(1);

	//Make the window visible
	glfwShowWindow(glfwWindow);

	//cangeScene(1);

}

void Window::loop() {

	//Check for event listener status
	bool is_key_listener_okay;
	bool is_mouse_listener_okay;

	for (int i = 0; i <= 356; i++) {
		if (KeyListener::get()->keyPressed[i] == false) {
			is_key_listener_okay = true;
		}
		else {
			is_key_listener_okay = false;
		}
	}

	for (int i = 0; i <= 3; i++) {
		if (MouseListener::get()->mouseButtonPressed[i] == false) {
			is_mouse_listener_okay = true;
		}
		else {
			is_mouse_listener_okay = false;
		}

	}

	std::cout << "Key Listener Status: " << is_key_listener_okay << std::endl;
	std::cout << "Mouse Listener Status: " << is_mouse_listener_okay << std::endl;


	while (!glfwWindowShouldClose(glfwWindow)) {
		glfwPollEvents();


		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		

			

		glfwSwapBuffers(glfwWindow);
	}

	glfwDestroyWindow(glfwWindow);
}