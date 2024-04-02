#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(float x, float y);

	void Update(float deltaTime) override;
	void Draw() override;

	static Player* GetInstance();

private:
	static Player* instance;

private:
	float mSpeed = 10.0f;
};

