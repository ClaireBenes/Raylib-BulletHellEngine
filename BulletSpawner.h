#pragma once

#include "GameObject.h"
#include "Bullet.h"

#include <memory>

class BulletSpawner : public GameObject
{
public:
	BulletSpawner(float x, float y);

	void Update(float deltaTime) override;
	void Draw() override;

public:
	const float SPAWN_TIME = 0.5f;
	float mSpawnTime = SPAWN_TIME;

	//bullet to shoot 
	//will have to update it's data
 	std::shared_ptr<Bullet> bullet;
	
	//add list of attack pattern
};

