#pragma once
#include<vector>
#include <memory>

class GameObject;

class GameManager
{
public:
	GameManager();

	void Update(float deltaTime);
	void Draw();

	void ToAddObject(std::shared_ptr<GameObject> object);
	void ToEraseObject(std::shared_ptr<GameObject> object);

	static GameManager* GetInstance();

private:
	static GameManager* instance;

private:
	std::vector<std::shared_ptr<GameObject>> mObjectToAdd;
	std::vector<std::shared_ptr<GameObject>> mObjects;
	std::vector<std::shared_ptr<GameObject>> mObjectToErase;
};

