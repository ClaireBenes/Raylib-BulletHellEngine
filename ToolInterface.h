#pragma once
class ToolInterface
{
public:
	void Update();
	void Draw();

	void BulletEditor();
	void AttackPatternEditor();

private:
	int mAttackpatternNumber = 0;
	//std::vector<BulletData> allBullets;
};

