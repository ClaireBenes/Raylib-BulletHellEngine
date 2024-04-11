#pragma once

#include "AttackPatternData.h"
#include "BulletData.h"
#include "BulletSpawner.h"
#include "GameManager.h"

#include <vector>

class ToolInterface
{
public:
	void Init();
	void Update();
	void Draw();

	void BulletEditor();
	void AttackPatternEditor();
	void SetBulletSpawner(std::shared_ptr<BulletSpawner> bulletSpawner);
	void UpdateBulletSpawner();

private:
	std::vector<std::shared_ptr<BulletData>> mAllBullets;
	std::vector<AttackPatternData> mAllAttackPattern;
	std::shared_ptr<BulletSpawner> mBulletSpawner;

	int mCurrentBulletIndex = 0;
};

