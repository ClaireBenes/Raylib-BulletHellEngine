#pragma once
#include<vector>

class GameObject;

class GameManager
{
public:
	GameManager();

	void Update(float deltaTime);
	void Draw();

	static GameManager* GetInstance();

private:
	static GameManager* instance;

private:
	std::vector<GameObject*> mObjectToAdd;
	std::vector<GameObject*> mObjects;
	std::vector<GameObject*> mObjectToErase;
};

