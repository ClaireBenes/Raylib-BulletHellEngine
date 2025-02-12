#pragma once

#include "Engine/GameObject.h"
#include "Bullet.h"
#include "Engine/AttackPatternData.h"

#include <memory>
#include <vector>

class BulletSpawner : public GameObject
{
public:
	BulletSpawner(float x, float y);

	void Update(float deltaTime) override;
	void Draw() override;

	void SpawnBullets(const AttackPatternData& data);
	void AddAttackPattern(const AttackPatternData& attackPattern);
	void ClearAttackPatterns();

public:
	const float SPAWN_TIME = 0.5f;
	float mSpawnTime = SPAWN_TIME;
	Texture2D mTexture;

private:
	std::vector<AttackPatternData> mAttackPatternData;
	std::vector<float> mAttackPatternTimer;
	float mScreenWidth = 0;
};

