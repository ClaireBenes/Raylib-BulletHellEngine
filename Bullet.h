#pragma once

#include "GameObject.h"

class Bullet : public GameObject
{
public:
	void Update(float deltaTime) override;
	void Draw() override;

public:
	float timeToKill = 2.0f;
};

