#pragma once

class GameManager
{
public:
	GameManager();

	static GameManager* GetInstance();

private:
	static GameManager* instance;
};

