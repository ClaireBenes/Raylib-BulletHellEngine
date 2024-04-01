#pragma once

#include "GameObject.h"

class Bullet : public GameObject
{
public:
	void Update(float deltaTime) override;
	void Draw() override;

public:
	float mTimeBeforeKill = 3.0f; //to Erase

	//Bullet data
};

