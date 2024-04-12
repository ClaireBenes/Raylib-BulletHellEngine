#include "Bullet.h"
#include "Player.h"

void Bullet::Update(float deltaTime)
{
	//rotation and position of bullet overTime
	mAngle += mBulletData->mAngularVelocity * deltaTime;

	float x = mX + cos(mAngle) * (mBulletData->mSpeed * deltaTime);
	float y = mY + sin(mAngle) * (mBulletData->mSpeed * deltaTime);

	mX = x;
	mY = y;

	//Destroy bullet when out of screen -- Will need to change it when the tool will appear
	if (mX + mBulletData->mSize < 0 - mBulletData->mSize || mX - mBulletData->mSize > 760 + mBulletData->mSize ||
		mY + mBulletData->mSize < 0 - mBulletData->mSize || mY - mBulletData->mSize > GetScreenHeight() + mBulletData->mSize)
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
	DrawCircle(mX, mY, mSize, BLANK);

	Rectangle source { 0, 0, 16, 16 };
	Rectangle dest { mX, mY, mSize * 2.0f, mSize * 2.0f };
	dest.x -= dest.width / 2.0f;
	dest.y -= dest.height / 2.0f;
	Vector2 origin { 0.5f, 0.5f };

	DrawTexturePro(mBulletData->mInnerImage, source, dest, origin, 0, WHITE);
	DrawTexturePro(mBulletData->mOuterImage, source, dest, origin, 0, mBulletData->mColor);
}

void Bullet::ChangeBulletData(std::shared_ptr<BulletData> newData)
{
	mBulletData = newData;
}
