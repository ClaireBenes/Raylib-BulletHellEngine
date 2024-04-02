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
	//Move player toward mouse pos
	mX -= (mX - GetMouseX()) * mSpeed * deltaTime;
	mY -= (mY - GetMouseY()) * mSpeed *deltaTime;
}

void Player::Draw()
{
	//Size & position of the player
	mSize = 8;
	DrawCircle(mX - mSize / 4.0f, mY - mSize / 4.0f, mSize, RED);
	DrawCircle(mX - mSize / 4.0f, mY - mSize / 4.0f, mSize / 1.3f, WHITE);

	//Draw Player Texture behind too
}

Player* Player::GetInstance()
{
	return instance;
}
