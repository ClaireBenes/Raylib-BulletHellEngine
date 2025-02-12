#pragma once

#include "Engine/GameObject.h"
#include "BulletData.h"

class Bullet : public GameObject
{
public:
	void Update(float deltaTime) override;
	void Draw() override;

	void ChangeBulletData(std::shared_ptr<BulletData> newData);

public:
	std::shared_ptr<BulletData> mBulletData;
};

