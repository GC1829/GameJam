#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"

#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
	m_camera = NewGO<Camera>(0);
}

Game::~Game()
{
}
bool Game::Start()
{
	NewGO<Enemy>(0, "enemy");
	return 0;
}
void Game::Update()
{
	QueryGOs<Enemy>("enemy", [&](Enemy* enemy) {
		//�ǂɒׂ��ꂽ�Ƃ���Enemy������

		DeleteGO(enemy);
		return true;
		});
	QueryGOs<Enemy>("enemy", [&](Enemy* enemy) {
		if (enemy == 0) {
			//Enemy��0�ɂȂ�����GameClaer��\��
			
			//CSpritRender�̃C���X�^���X���쐬
			m_spritRender = NewGO<prefab::CSpriteRender>(0);
			//�^�C�g����ʂ̃��[�h
			m_spritRender->Init(L"", 1280.0f, 720.0f);
			return true;
		}
		return true;
		});

}