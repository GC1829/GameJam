#pragma once
class EnemyGenerator : public IGameObject
{
public:
	EnemyGenerator();
	~EnemyGenerator();

	void Update();

	int m_timer = 0;
	int m_count = 0;
	int state = 0;
};

