#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(float x, float y);

	void Update(float deltaTime) override;
	void Draw() override;
	void GetHurt();
	void SetInEditor(bool isInEditor);
	bool CheckIfInEditor();

	static Player* GetInstance();

public:
	const float RESPAWN_TIME = 2.0f;
	const float INVINCIBILITY_TIME = 3.5f;
	float mRespawnTime = RESPAWN_TIME;
	float mInvincibilityTime = INVINCIBILITY_TIME;

private:
	float mSpeed = 10.0f;
	float mRespawnSpeed = 3.0f;

	bool mIsHurt = false;
	bool mIsInvincible = false;
	bool mIsInEditor = true;

private:
	static Player* instance;
};

