#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "TakaraBako.h"
#include "EnemyGenerator.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
	m_camera = NewGO<Camera>(0);
	m_map = NewGO<Map>(0);
	m_player = NewGO<Player>(0);
	//m_enemy2 = NewGO<Enemy2>(0);
	NewGO<EnemyGenerator>(0);
	m_takarabako = NewGO<TakaraBako>(0);
}

Game::~Game()
{
}
bool Game::Start()
{
	return true;
}
void Game::Update()
{

	if (takarabako == 0)
	{
		m_spritRender = NewGO<prefab::CSpriteRender>(0);
		//�^�C�g����ʂ̃��[�h
		//m_spritRender->Init(L"../Assets/Sprite/GAMEOVER.dds", 1280.0f, 720.0f);
	}
	//QueryGOs<Enemy>("enemy", [&](Enemy* enemy) {
	//	//�ǂɒׂ��ꂽ�Ƃ���Enemy������

	//	DeleteGO(enemy);
	//	return true;
	//	});1
	//QueryGOs<Enemy>("enemy", [&](Enemy* enemy) {
	//	if (enemy == 0) {
	//		//Enemy��0�ɂȂ�����GameClaer��\��
	//		
			////CSpritRender�̃C���X�^���X���쐬
			//m_spritRender = NewGO<prefab::CSpriteRender>(0);
			////�^�C�g����ʂ̃��[�h
			//m_spritRender->Init(L"../Assets/sprite/GAMECLAER.dds", 500.0f, 360.0f);
	//		m_spritRender->SetPosition(position);
	//		position.x += 1.0f;
	//		position.y += 1.0f;
	//		position.z += 1.0f;

	//�G�t�F�N�g�̃C���X�^���X�̍쐬
	//prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	////�Đ�
	//effect->Play(L"effect/");
	////�G�t�F�N�g�̔����ʒu
	//effect->SetPosition();
	//return true;
	//	}
	//	return true;
	//	});


	
	//QueryGOs<Enemy>("enemy", [&](Enemy* enemy) {
	//	//2�_�Ԃ̋������v�Z����
	//Player* m_player = FindGO<Player>("m_player");	
	//CVector3 diff = enemy->m_position - m_position;
	////2�_�Ԃ̋������`�ȉ��ɂȂ��������
	//if (diff.Length() <= 0.0f) {
	//	takarabako = 0;
	//	DeleteGO(enemy);
	//}
	//		return true;
	//		});
	//if (takarabako == 0) {
	//	//CSpritRender�̃C���X�^���X���쐬
	//	m_spritRender = NewGO<prefab::CSpriteRender>(0);
	//	//�^�C�g����ʂ̃��[�h
	//	m_spritRender->Init(L"../Assets/Sprite/GAMEOVER.dds", 1280.0f, 720.0f);
	//}

}


