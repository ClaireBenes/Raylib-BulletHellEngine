#pragma once

#include "GameObject.h"
#include "BulletData.h"

class Bullet : public GameObject
{
public:
	void Update(float deltaTime) override;
	void Draw() override;

	void ChangeBulletData(BulletData newData);

public:
	BulletData mBulletData;
};

