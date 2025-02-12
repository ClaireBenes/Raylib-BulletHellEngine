#include "Bullet.h"
#include "Game/Player.h"

void Bullet::Update(float deltaTime)
{
	//rotation and position of bullet overTime
	mAngle += mBulletData->mAngularVelocity * (PI / 180.0f) * deltaTime;

	float x = mX + cos(mAngle) * (mBulletData->mSpeed * deltaTime);
	float y = mY + sin(mAngle) * (mBulletData->mSpeed * deltaTime);

	mX = x;
	mY = y;

	//Destroy bullet when out of screen -- Will need to change it when the tool will appear
	if (mX + mBulletData->mSize < 0 - mBulletData->mSize || mX - mBulletData->mSize > 750 ||
		mY + mBulletData->mSize < 0 - mBulletData->mSize || mY - mBulletData->mSize > GetScreenHeight())
	{
		mManager->ToEraseObject(shared_from_this());
	}

	//Check collision between player and bullets
	auto player = Player::GetInstance();
	if (CheckCollisionPointCircle({ player->mX, player->mY }, { mX, mY }, mSize))
	{
		player->GetHurt();
	}
}

void Bullet::Draw()
{
	//Show bullet
	mSize = mBulletData->mSize;

	Rectangle source { 0, 0, 16, 16 };
	Rectangle dest { mX, mY, mSize * 2.0f, mSize * 2.0f };
	//DrawRectangleLinesEx(dest, 2.0f, RED);
	Vector2 origin { mSize, mSize };

	DrawTexturePro(mBulletData->mInnerImage, source, dest, origin, mAngle * (180/PI), WHITE);
	DrawTexturePro(mBulletData->mOuterImage, source, dest, origin, mAngle * (180/PI), mBulletData->mColor);
}

void Bullet::ChangeBulletData(std::shared_ptr<BulletData> newData)
{
	mBulletData = newData;
}
