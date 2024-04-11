#pragma once

#include "AttackPatternData.h"
#include "BulletData.h"
#include "BulletSpawner.h"
#include "GameManager.h"

#include <vector>

class ToolInterface
{
public:
	void Update();
	void Draw();

	void BulletEditor();
	void AttackPatternEditor();
	void SetBulletSpawner(std::shared_ptr<BulletSpawner> bulletSpawner);
	void UpdateBulletSpawner();

private:
	std::vector<BulletData> mAllBullets;
	std::vector<AttackPatternData> mAllAttackPattern;
	std::shared_ptr<BulletSpawner> mBulletSpawner;
};

