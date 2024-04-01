#include "Bullet.h"

void Bullet::Update(float deltaTime)
{
	//Position
	mX += mSpeed * deltaTime;

	//Time before killing object that we want to destroy
	//*************** Will have to replace with offscreen Logic **********************************
	mTimeBeforeKill -= deltaTime;
	if (mTimeBeforeKill <= 0.0f)
	{
		//kill object
		mManager->ToEraseObject(shared_from_this());
		mTimeBeforeKill = 3.0f;
	}
}

void Bullet::Draw()
{
	//Show bullet
	DrawCircle(mX, mY, 10 * mScale, mColor);
}

void Bullet::ChangeBulletData(BulletData newData)
{
	mBulletData = newData;
	UpdateBulletData();
}

void Bullet::UpdateBulletData()
{
	mColor = mBulletData.mColor;
	mSpeed = mBulletData.mSpeed;
	mScale = mBulletData.mScale;
	mAngularVelocity = mBulletData.mAngularVelocity;
}
