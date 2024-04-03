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
	//if player is not hurt and has respawned
	if(!mIsHurt)
	{
		//Move player toward mouse pos
		mX -= (mX - GetMouseX()) * mSpeed * deltaTime;
		mY -= (mY - GetMouseY()) * mSpeed * deltaTime;
	}

	//if player got hurt
	if (mIsInvincible)
	{
		mX -= (mX - (780 / 2.0f)) * mRespawnSpeed * deltaTime;
		mY -= (mY - (960 / 1.1f)) * mRespawnSpeed * deltaTime;

		//Timer to respawn and play again
		mRespawnTime -= deltaTime;
		if (mRespawnTime <= 0.0f)
		{
			mRespawnTime += RESPAWN_TIME;
			mIsHurt = false;
		}

		//Timer of invinciblity (longer than respawn)
		mInvincibilityTime -= deltaTime;
		if (mInvincibilityTime <= 0.0f)
		{
			mInvincibilityTime += INVINCIBILITY_TIME;
			mIsInvincible = false;
		}
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
	if (!mIsInvincible)
	{
		mIsHurt = true;
	}

	mIsInvincible = true;
}

Player* Player::GetInstance()
{
	return instance;
}
