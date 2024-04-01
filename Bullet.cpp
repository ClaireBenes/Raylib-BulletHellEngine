#include "Bullet.h"

void Bullet::Update(float deltaTime)
{
	//Position
	mX += 50.0f * deltaTime;

	//Time before killing object that we want to destroy
	mTimeBeforeKill -= deltaTime;
	if (mTimeBeforeKill <= 0.0f)
	{
		GameManager* manager = GameManager::GetInstance();
		//kill object
	}
}

void Bullet::Draw()
{
	DrawCircle(mX, mY, 50, RED);
}
