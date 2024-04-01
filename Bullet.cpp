#include "Bullet.h"

void Bullet::Update(float deltaTime)
{
	//Position
	mX += mBulletData.mSpeed * deltaTime;

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
	DrawCircle(mX, mY, 10 * mBulletData.mScale, mBulletData.mColor);
}

void Bullet::ChangeBulletData(BulletData newData)
{
	mBulletData = newData;
}
