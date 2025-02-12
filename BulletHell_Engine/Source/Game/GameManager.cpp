#include "GameManager.h"

#include "Engine/GameObject.h"

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

void GameManager::EraseAllBullets()
{
	for (int object = mObjects.size() - 1; object > 1 ; object--)
	{
		ToEraseObject(mObjects[object]);
	}
}

std::vector<std::shared_ptr<GameObject>> GameManager::GetAllGameObjects()
{
	return mObjects;
}

GameManager* GameManager::GetInstance()
{
	return instance;
}
