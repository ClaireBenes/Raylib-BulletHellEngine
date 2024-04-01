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
			SpawnBullets(mAttackPatternData[i]);
		}

		//transform.rotation *= Quaternion.Euler(transform.rotation.x, transform.rotation.y, attackPattern.rotationSpeed * Time.deltaTime);
	}
}

void BulletSpawner::SpawnBullets(const AttackPatternData& data)
{
	float constantOffset = 2*PI / data.bulletCount;

	for (int i = 0; i < data.bulletCount; i++)
	{
		auto bullet = std::make_shared<Bullet>();
		bullet->ChangeBulletData(data.bulletdata);
		bullet->mAngle = constantOffset * i + data.bulletRotationOffset;;

		bullet->mX = mX;
		bullet->mY = mY;

		mManager->ToAddObject(bullet);
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
