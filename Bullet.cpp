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

	DrawTextureEx(mBulletData->mInnerImage, { mX - mSize * mBulletData->mInnerImage.width / 6.5f,
		mY - mSize * mBulletData->mInnerImage.height / 6.5f }, 0, mSize * 0.3f, WHITE);
	DrawTextureEx(mBulletData->mOuterImage, { mX - mSize * mBulletData->mOuterImage.width / 6.5f,
		mY - mSize * mBulletData->mOuterImage.height / 6.5f }, 0, mSize * 0.3f, mBulletData->mColor);

}

void Bullet::ChangeBulletData(std::shared_ptr<BulletData> newData)
{
	mBulletData = newData;
}
