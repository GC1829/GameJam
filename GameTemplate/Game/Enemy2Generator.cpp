#include "stdafx.h"
#include "Enemy2Generator.h"
#include "Enemy2.h"

Enemy2Generator::Enemy2Generator()
{
}

Enemy2Generator::~Enemy2Generator()
{
	DeleteGO(m_enemy2generator);
}

void Enemy2Generator::Update()
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
			Enemy2* enemy2 = NewGO<Enemy2>(0, "enemy2");
			enemy2->m_position = { -1000.0f, 0.0f, 1000.0f };
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