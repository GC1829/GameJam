#pragma once
class EnemyGenerator : public IGameObject
{
public:
	EnemyGenerator();
	~EnemyGenerator();

	void Update();

	EnemyGenerator* m_enemygenerator = nullptr;

	int m_timer = 0;
	int m_count = 0;
	int state = 2;
};

