#pragma once


#include "Scene.h"
#include <string>

class LevelEditorScene : public Scene {
public:
	void update(float dt);
	void init();
	LevelEditorScene();
private:
	unsigned int buffer;
};