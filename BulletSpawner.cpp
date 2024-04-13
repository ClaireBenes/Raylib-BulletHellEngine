#include "BulletSpawner.h"

BulletSpawner::BulletSpawner(float x, float y)
{
	mX = x;
	mY = y;
	//mTexture = LoadTexture("resources/black-hole.png");
}

void BulletSpawner::Update(float deltaTime)
{
	//For every attack pattern in the list
	for (int i = 0; i < mAttackPatternData.size(); i++)
	{
		//spawn bullet at different time rate
		mAttackPatternTimer[i] -= deltaTime;
		if (mAttackPatternTimer[i] <= 0.0f)
		{
			mAttackPatternTimer[i] += mAttackPatternData[i].timeBetweenBullet;

			SpawnBullets(mAttackPatternData[i]);
		}
		//Rotate attack pattern
		mAttackPatternData[i].bulletRotationOffset += mAttackPatternData[i].rotationSpeed * deltaTime;
	}
}

void BulletSpawner::SpawnBullets(const AttackPatternData& data)
{
	//Offset in radiant considering number of bullet
	float constantOffset = 2*PI / data.bulletCount;

	//create a bullet for every bullet in said pattern
	for (int i = 0; i < data.bulletCount; i++)
	{
		auto bullet = std::make_shared<Bullet>();
		bullet->ChangeBulletData(data.bulletData);
		bullet->mAngle = constantOffset * i + (data.bulletRotationOffset * (PI / 180.0f));

		bullet->mX = mX;
		bullet->mY = mY;

		mManager->ToAddObject(bullet);
	}
}

void BulletSpawner::Draw()
{
	//Size & position of the bulletSpawner
	mSize = 16;
	float textureSize = 1.5f;
	DrawRectangle(mX - mSize / 2.0f, mY - mSize / 2.0f, mSize, mSize, BLUE);
	DrawTextureEx(mTexture, { mX - mTexture.width / 1.5f, mY - mTexture.height / 1.5f }, 0, textureSize, WHITE);
}


void BulletSpawner::AddAttackPattern(const AttackPatternData& attackPattern)
{
	mAttackPatternData.push_back(attackPattern);
	mAttackPatternTimer.push_back(attackPattern.timeBetweenBullet);
}

void BulletSpawner::ClearAttackPatterns()
{
	mAttackPatternData.clear();
	mAttackPatternTimer.clear();
}
