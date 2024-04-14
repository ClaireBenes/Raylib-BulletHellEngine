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

	std::vector<std::shared_ptr<GameObject>> GetAllGameObjects();

	static GameManager* GetInstance();

private:
	static GameManager* instance;

private:
	//using smart (shared) pointer to automatically deallocate the objects when they are not referenced anymore
	std::vector<std::shared_ptr<GameObject>> mObjectToAdd;
	std::vector<std::shared_ptr<GameObject>> mObjects;
	std::vector<std::shared_ptr<GameObject>> mObjectToErase;
};

