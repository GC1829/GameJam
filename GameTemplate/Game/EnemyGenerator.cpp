#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"

EnemyGenerator::EnemyGenerator()
{
}

EnemyGenerator::~EnemyGenerator()
{
}

void EnemyGenerator::Update()
{
	if (state == 0) {
		m_timer++;
		if (m_timer == 120) {
			m_timer = 0;
			Enemy* enemy = NewGO<Enemy>(0,"enemy");
			enemy->m_position = { -1000.0f, 0.0f, 1000.0f };
			m_count++;

			if (m_count == 5) {
				state = 1;
			}
		}
		else if (state == 1) {
		}
	}

}