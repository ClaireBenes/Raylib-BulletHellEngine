#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(float x, float y);

	void Update(float deltaTime) override;
	void Draw() override;
	void GetHurt();

	static Player* GetInstance();

public:
	const float respawnTime = 2.0f;
	float RESPAWN_TIME = respawnTime;

private:
	float mSpeed = 10.0f;
	float mRespawnSpeed = 3.0f;
	bool mIsHurt = false;

private:
	static Player* instance;


};

