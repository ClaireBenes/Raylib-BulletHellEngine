#pragma once
#include "raylib.h"
#include "Game/GameManager.h"

#include <memory>
#include <cmath>

class GameObject : public std::enable_shared_from_this<GameObject>
{
public:
	GameObject();

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

public:
	float mX, mY;
	float mAngle;
	float mSize;

protected:
	GameManager* mManager;
};

