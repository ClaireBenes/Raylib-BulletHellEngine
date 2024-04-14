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
	if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_E))
	{
		mIsInEditor = true;
	}
	else if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_P))
	{
		mIsInEditor = false;
	}

	if (mIsInEditor)
	{
		mX = 780 / 2.0f;
		mY = 960 / 1.1f;

		mIsHurt = false;
		mIsInvincible = true;
	}

	//if player is not hurt and has respawned
	if(!mIsHurt && !mIsInEditor)
	{
		//if mouse on the editor
		if (GetMouseX() > 770)
		{
			mX = 765;
			mY -= (mY - GetMouseY()) * mSpeed * deltaTime;
		}
		else
		{
			//Move player toward mouse pos
			mX -= (mX - GetMouseX()) * mSpeed * deltaTime;
			mY -= (mY - GetMouseY()) * mSpeed * deltaTime;
		}

	}

	//if player got hurt
	if (mIsInvincible && !mIsInEditor)
	{
		if (mIsHurt)
		{
			//Move player to the bottom of screen - to respawn location
			mX -= (mX - (780 / 2.0f)) * mRespawnSpeed * deltaTime;
			mY -= (mY - (960 / 1.1f)) * mRespawnSpeed * deltaTime;

			//Timer to respawn and play again
			mRespawnTime -= deltaTime;
			if (mRespawnTime <= 0.0f)
			{
				mIsHurt = false;
			}
		}

		//Timer of invinciblity (longer than respawn)
		mInvincibilityTime -= deltaTime;
		if (mInvincibilityTime <= 0.0f && GetMouseX() < 780)
		{
			mIsInvincible = false;
		}
	}
}

void Player::Draw()
{
	//Size & position of the player
	mSize = 8;

	//If is invincible, see player less (less alpha)
	if (mIsInvincible)
	{
		DrawCircle(mX - mSize / 4.0f, mY - mSize / 4.0f, mSize, { 230, 41, 55, 50 });
		DrawCircle(mX - mSize / 4.0f, mY - mSize / 4.0f, mSize / 1.3f, { 255, 255, 255, 50 });
	}
	else
	{
		DrawCircle(mX - mSize / 4.0f, mY - mSize / 4.0f, mSize, RED);
		DrawCircle(mX - mSize / 4.0f, mY - mSize / 4.0f, mSize / 1.3f, WHITE);
	}

	//Red Screen when collides with bullet
	if (mIsHurt && !mIsInEditor)
	{
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), { 190, 33, 55, 80 });
	}
}

void Player::GetHurt()
{
	//if not invicible, get hurt
	if (!mIsInvincible && !mIsInEditor)
	{
		mRespawnTime = RESPAWN_TIME;
		mInvincibilityTime = INVINCIBILITY_TIME;

		mIsHurt = true;
		mIsInvincible = true;
	}
}

void Player::SetInEditor(bool isInEditor)
{
	mIsInEditor = isInEditor;
}

bool Player::CheckIfInEditor()
{
	return mIsInEditor;
}

Player* Player::GetInstance()
{
	return instance;
}
