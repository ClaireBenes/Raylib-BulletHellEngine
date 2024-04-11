#pragma once

#include "GameObject.h"
#include "Bullet.h"
#include "AttackPatternData.h"

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

private:
	std::vector<AttackPatternData> mAttackPatternData;
	std::vector<float> mAttackPatternTimer;
};

