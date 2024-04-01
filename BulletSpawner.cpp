#include "BulletSpawner.h"

BulletSpawner::BulletSpawner(float x, float y)
{
	mX = x;
	mY = y;
}

void BulletSpawner::Update(float deltaTime)
{
	//Time before adding bullet that we want to create in game
	mSpawnTime -= deltaTime;
	if (mSpawnTime <= 0.0f)
	{
		mSpawnTime += SPAWN_TIME;

		//auto bullet = std::make_shared<Bullet>();
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
