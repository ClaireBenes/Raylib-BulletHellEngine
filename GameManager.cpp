#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
	instance = this;
}

GameManager* GameManager::GetInstance()
{
	return instance;
}
