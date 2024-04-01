#pragma once

#include "GameObject.h"
#include "BulletData.h"

class Bullet : public GameObject
{
public:
	void Update(float deltaTime) override;
	void Draw() override;

	void ChangeBulletData(BulletData newData);
	void UpdateBulletData();

public:
	float mTimeBeforeKill = 3.0f; //to Erase

	BulletData mBulletData;

	Color mColor = RED;
	float mSpeed = 50;
	float mAngularVelocity = 10;
	float mScale = 1;


};

