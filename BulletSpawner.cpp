#include "BulletSpawner.h"

BulletSpawner::BulletSpawner(float x, float y)
{
	mX = x;
	mY = y;
}

void BulletSpawner::Update(float deltaTime)
{
	for (int i = 0; i < mAttackPatternData.size(); i++)
	{
		mAttackPatternTimer[i] -= deltaTime;
		if (mAttackPatternTimer[i] <= 0.0f)
		{
			mAttackPatternTimer[i] += mAttackPatternData[i].timeBetweenBullet;

			auto bullet = std::make_shared<Bullet>();
			bullet->ChangeBulletData(mAttackPatternData[i].bulletdata);
			bullet->mX = mX;
			bullet->mY = mY;

			mManager->ToAddObject(bullet);
		}
	}
}

void BulletSpawner::Draw()
{
	//Size & position of the bulletSpawner
	int size = 16;
	DrawRectangle(mX - size / 2.0f, mY - size / 2.0f, size, size, BLUE);
}

void BulletSpawner::AddAttackPattern(const AttackPatternData& attackPattern)
{
	mAttackPatternData.push_back(attackPattern);
	mAttackPatternTimer.push_back(attackPattern.timeBetweenBullet);
}
