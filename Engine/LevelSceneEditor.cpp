#include "LevelSceneEditor.h"

#include <iostream>
#include "KeyListener.h"
#include "Window.h"					

#include <glad/glad.h>

void LevelEditorScene::update(float dt)
{

	glDrawArrays(GL_TRIANGLES, 0, 4);

}

void LevelEditorScene::init()
{
	float positions[6] = {
		-0.5f,-0.5f,
		0.5f , 0.5f,
		0.5f ,-0.5f
	};

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), positions, GL_STATIC_DRAW);
}

LevelEditorScene::LevelEditorScene()
{
	std::cout << "Level Editor Scene has been loaded up" << std::endl;

	

}