#include "Bullet.h"

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
}

void Bullet::Draw()
{
	//Show bullet
	//change 10 with size
	DrawCircle(mX, mY, mBulletData.mSize, mBulletData.mColor);
}

void Bullet::ChangeBulletData(BulletData newData)
{
	mBulletData = newData;
}
