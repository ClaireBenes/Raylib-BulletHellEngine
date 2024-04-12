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
	void Draw();

	void BulletEditor();
	void AttackPatternEditor();
	void SetBulletSpawner(std::shared_ptr<BulletSpawner> bulletSpawner);
	void UpdateBulletSpawner();

	void UpdateBulletRenderTexture();

private:
	std::vector<std::shared_ptr<BulletData>> mAllBullets;
	std::vector<AttackPatternData> mAllAttackPattern;
	std::shared_ptr<BulletSpawner> mBulletSpawner;

	std::vector<const char*> mBulletNames;
	int mCurrentBulletIndex = 0;
	char mNewBulletName[64] = "Elaine";

	RenderTexture2D mBulletRenderTexture;
};

