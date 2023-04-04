#include "LevelSceneEditor.h"

#include <iostream>
#include "KeyListener.h"
#include "Window.h"					

void LevelEditorScene::update(float dt)
{
	if (KeyListener::isKeyPressed(GLFW_KEY_A)) {
		std::cout << "fuck";
	}
}

void LevelEditorScene::init()
{
	
}

LevelEditorScene::LevelEditorScene()
{
	std::cout << "Level Editor Scene has been loaded up" << std::endl;

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.0f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();

}