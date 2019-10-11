#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"

EnemyGenerator::EnemyGenerator()
{
}

EnemyGenerator::~EnemyGenerator()
{
	DeleteGO(m_enemygenerator);
}

void EnemyGenerator::Update()
{
	//�G�l�~�[�̔�����x�点��
	if (state == 2) {
		m_timer++;
		if (m_timer == 10) {
			m_timer = 0;
			state = 0;
		}
	}
	//�G�l�~�[�̎�������
	if (state == 0) {
		m_timer++;
		if (m_timer == 120) {
			m_timer = 0;
			Enemy* enemy = NewGO<Enemy>(0, "enemy");
			enemy->m_position = { -1000.0f, 0.0f, 1000.0f };
			m_count++;

			if (m_count == 5) {
				state = 1;
			}
		}
	}
	//�G�l�~�[�������~
	if (state == 1) {
		DeleteGO(this);
	}
	
}