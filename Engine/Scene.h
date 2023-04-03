#pragma once


class Scene {
public:
	virtual void update(float dt) = 0;
	virtual void init() = 0;
	Scene();
};