#include "Player.h"

Player* Player::instance = nullptr;

Player::Player(float x, float y)
{
	instance = this;
	mX = x;
	mY = y;
}

void Player::Update(float deltaTime)
{
	//if 
	if (mIsHurt)
	{
		mX -= (mX - (780 / 2.0f)) * mRespawnSpeed * deltaTime;
		mY -= (mY - (960 / 1.1f)) * mRespawnSpeed * deltaTime;

		RESPAWN_TIME -= deltaTime;
		if (RESPAWN_TIME <= 0.0f)
		{
			RESPAWN_TIME += respawnTime;
			mIsHurt = false;
		}
	}
	else
	{
		//Move player toward mouse pos
		mX -= (mX - GetMouseX()) * mSpeed * deltaTime;
		mY -= (mY - GetMouseY()) * mSpeed * deltaTime;
	}
}

void Player::Draw()
{
	//Size & position of the player
	mSize = 8;
	DrawCircle(mX - mSize / 4.0f, mY - mSize / 4.0f, mSize, RED);
	DrawCircle(mX - mSize / 4.0f, mY - mSize / 4.0f, mSize / 1.3f, WHITE);

	//Draw Player Texture behind too

	//Red Screen when collides with bullet
	if (mIsHurt)
	{
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), { 190, 33, 55, 80 });
	}
}

void Player::GetHurt()
{
	mIsHurt = true;

	//add some invincibility
	//do an invincibility timer that is longer
}

Player* Player::GetInstance()
{
	return instance;
}
