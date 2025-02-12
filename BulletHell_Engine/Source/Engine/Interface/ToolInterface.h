#pragma once

#include "Engine/AttackPatternData.h"
#include "Engine/Bullet/BulletData.h"
#include "Engine/Bullet/BulletSpawner.h"
#include "Game/GameManager.h"

#include <vector>

class ToolInterface
{
public:
	ToolInterface();

	void Init();
	void Draw();

	void TopMenuBar();

	void BulletEditor();
	void AttackPatternEditor();
	void SetBulletSpawner(std::shared_ptr<BulletSpawner> bulletSpawner);
	void UpdateBulletSpawner();

	void UpdateBulletRenderTexture();

private:
	std::vector<std::shared_ptr<BulletData>> mAllBullets;
	std::vector<AttackPatternData> mAllAttackPattern;
	std::shared_ptr<BulletSpawner> mBulletSpawner;

	std::vector<Texture2D> mBulletInnerTextures;
	std::vector<Texture2D> mBulletOuterTextures;
	std::vector<const char*> mBulletTexturesName;

	std::vector<const char*> mBulletNames;
	int mCurrentBulletIndex = 0;
	char mNewBulletName[64] = "Elaine";

	RenderTexture2D mBulletRenderTexture;

protected:
	GameManager* mManager;
};

