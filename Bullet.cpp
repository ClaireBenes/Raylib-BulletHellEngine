#include "Bullet.h"

void Bullet::Update(float deltaTime)
{
	//Position
	mX += 80.0f * deltaTime;

	//Time before killing object that we want to destroy
	//*************** Will have to replace with offscreen Logic **********************************
	mTimeBeforeKill -= deltaTime;
	if (mTimeBeforeKill <= 0.0f)
	{
		//kill object
		mManager->ToEraseObject(shared_from_this());
	}
}

void Bullet::Draw()
{
	//Show bullet
	DrawCircle(mX, mY, 10, RED);
}
