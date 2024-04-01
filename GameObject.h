#pragma once
#include "GameManager.h"

class GameObject
{
public:
	GameObject();

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

public:
	float mX, mY;
	float mAngle;

protected:
	GameManager* mManager;
};

