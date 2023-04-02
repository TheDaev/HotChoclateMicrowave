#pragma once

#include "Scene.h"

class LevelScene : public Scene {
public:
	void update(float dt);
	void init();
	LevelScene();
};

