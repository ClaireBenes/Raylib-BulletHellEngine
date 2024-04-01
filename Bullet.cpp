#include "Bullet.h"

void Bullet::Update(float deltaTime)
{
	//rotation and position of bullet overTime
	mAngle += mBulletData.mAngularVelocity * deltaTime;

	float x = mX + cos(mAngle) * (mBulletData.mSpeed * deltaTime);
	float y = mY + sin(mAngle) * (mBulletData.mSpeed * deltaTime);

	mX = x;
	mY = y;

	//Time before killing object that we want to destroy
	//*************** Will have to replace with offscreen Logic **********************************
	
	//mTimeBeforeKill -= deltaTime;
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
