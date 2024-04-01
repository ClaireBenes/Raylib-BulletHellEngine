#include "Bullet.h"

void Bullet::Update(float deltaTime)
{
	//Position
	mX += 50.0f * deltaTime;

	timeToKill -= deltaTime;
	if (timeToKill <= 0.0f)
	{

	}
}

void Bullet::Draw()
{
}
