#pragma once

#include "GameObject.h"
#include "Bullet.h"

class BulletSpawner : public GameObject
{
public:
	BulletSpawner(float x, float y);

	void Update(float deltaTime) override;
	void Draw() override;

public:
	const float SPAWN_TIME = 0.5f;
	float mSpawnTime = SPAWN_TIME;
};

