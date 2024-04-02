#include "Bullet.h"
#include "Player.h"

#include <iostream>

void Bullet::Update(float deltaTime)
{
	//rotation and position of bullet overTime
	mAngle += mBulletData.mAngularVelocity * deltaTime;

	float x = mX + cos(mAngle) * (mBulletData.mSpeed * deltaTime);
	float y = mY + sin(mAngle) * (mBulletData.mSpeed * deltaTime);

	mX = x;
	mY = y;

	//Destroy bullet when out of screen -- Will need to change it when the tool will appear
	if (mX + mBulletData.mSize < 0 - mBulletData.mSize || mX - mBulletData.mSize > GetScreenWidth() + mBulletData.mSize || 
		mY + mBulletData.mSize < 0 - mBulletData.mSize || mY - mBulletData.mSize > GetScreenHeight() + mBulletData.mSize)
	{
		mManager->ToEraseObject(shared_from_this());
	}

	//Check collision between player and bullets
	auto player = Player::GetInstance();
	if (CheckCollisionCircles({ mX, mY }, mSize ,{ player->mX, player->mY }, player->mSize))
	{
		//will have to change -- erase iostream on top too
		std::cout << player->mX << std::endl;
		//Red screen to indicate you are hurt
	}
}

void Bullet::Draw()
{
	//Show bullet
	mSize = mBulletData.mSize;
	DrawCircle(mX, mY, mSize, mBulletData.mColor);
}

void Bullet::ChangeBulletData(BulletData newData)
{
	mBulletData = newData;
}
