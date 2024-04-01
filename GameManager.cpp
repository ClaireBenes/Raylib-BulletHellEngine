#include "GameManager.h"

#include "GameObject.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
	instance = this;
}

void GameManager::Update(float deltaTime)
{
	//Adding object that need to be added
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

	//Erasing object that need to be killed
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

GameManager* GameManager::GetInstance()
{
	return instance;
}
