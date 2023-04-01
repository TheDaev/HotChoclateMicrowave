#include "Window.h"
#include "MouseListener.h"
#include "KeyListener.h"

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

	glfwDestroyWindow(glfwWindow);
	glfwTerminate();
	delete this;
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

}

void Window::loop() {
	while (!glfwWindowShouldClose(glfwWindow)) {
		glfwPollEvents();


		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		//idk whats wrong wit this

		/*if (KeyListener::isKeyPressed(GLFW_KEY_ESCAPE)) {
			static auto _ = [this]() {
				glfwDestroyWindow(glfwWindow);
				return true;
			}();
			return;
		}*/

		glfwSwapBuffers(glfwWindow);
	}

	glfwDestroyWindow(glfwWindow);
}