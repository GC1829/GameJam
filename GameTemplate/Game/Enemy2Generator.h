#pragma once
class Enemy2Generator : public IGameObject
{
public:
	Enemy2Generator();
	~Enemy2Generator();

	void Update();

	Enemy2Generator* m_enemy2generator = nullptr;

	int m_timer = 0;
	int m_count = 0;
	int state = 2;
};

