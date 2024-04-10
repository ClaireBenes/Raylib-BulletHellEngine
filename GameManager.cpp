#include "GameManager.h"

#include "GameObject.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
	instance = this;
}

void GameManager::Update(float deltaTime)
{
	//Adding object that we want to add
	for (auto& object : mObjectToAdd)
	{
		mObjects.push_back(object);
	}

	mObjectToAdd.clear();

	//Using update of objects
	for (auto& object : mObjects)
	{
		object->Update(deltaTime);
	}

	//Erasing object that we want to kill
	for (auto& object : mObjectToErase)
	{
		auto objectToKill = std::find(mObjects.begin(), mObjects.end(), object);

		if (objectToKill == mObjects.end())
		{
			continue;
		}

		mObjects.erase(objectToKill);
	}

	mObjectToErase.clear();
}

void GameManager::Draw()
{
	//Debug bullet count (gameObjects - bulletSpawner & player)
	//DrawText(TextFormat("Bullets : %i", mObjects.size() - 2), 10, 10, 30, RED);

	for (auto& object : mObjects)
	{
		object->Draw();
	}
}

//Add object to add to the list of all objects to add
void GameManager::ToAddObject(std::shared_ptr<GameObject> object)
{
	mObjectToAdd.push_back(object);
}

//Add object to erase to the list of all objects to erase
void GameManager::ToEraseObject(std::shared_ptr<GameObject> object)
{
	mObjectToErase.push_back(object);
}

GameManager* GameManager::GetInstance()
{
	return instance;
}
