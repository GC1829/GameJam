#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Player3.h"
#include "Player2.h"
#include "EnemyGenerator.h"
#include "Game.h"

CVector3 targetPoints1[9] = {
	{-195.300f, 0.0f, -195.000f},
	{193.000f,0.0f,-188.000f},
	{193.000f,0.0f,195.000f},
	{-107.167f,0.0f,171.36f},
	{-104.21f,0.0f,-150.000f},
	{92.754f,0.0f,-150.000f},
	{92.103f,0.0f,102.487f},
	{-24.000f,0.0f,80.000f},
	{-0.25f,0.0f,-10.000f}
};

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	DeleteGO(m_skinModelRender);
}

bool Enemy::Start()
{
	//�ǂɂԂ�����������]������+���X�~�܂�G�l�~�[
	//�X�L�����f�������_�[�̃C���X�^���X�̍쐬
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0, "enemy");
	//�X�L�����f�������_�[�̃��[�h
	m_skinModelRender->Init(L"../Assets/modelData/Enemy1.cmo");
	m_skinModelRender->SetScale({ 10.0f, 10.0f, 10.0f });
	//�X�L�����f���ɉ�]�N�H�[�^�j�I����ݒ肷��
	CQuaternion qRot;
	m_skinModelRender->SetRotation(qRot);
	m_player = FindGO<Player>("player");
	m_player2 = FindGO<Player2>("player2");
	m_player3 = FindGO<Player3>("player3");
	//m_game = FindGO<Game>("game");
	return true;
}

void Enemy::Update()
{
	if (state == 0) {
		//�����Ă���Ƃ�
		//���̈ړ���Ɍ������x�N�g�����v�Z����B
		CVector3 toNext = targetPoints1[m_targetPointNo1] * 5.3f - m_position;
		if (toNext.Length() < 10.0f) {
			//���̃|�C���g�ɍs���B
			m_targetPointNo1++;
		}
		toNext.Normalize();
		m_position += toNext * 10.f;
		Count++;

		if (Count == 50) {
			state = 1;
			Count = 0;
		}
	}
	else if (state == 1) {
		//�~�܂��Ă���Ƃ�
		Count2++;

		if (Count2 == 50) {
			state = 0;
			Count2 = 0;
		}

}
	Game* mm_game = FindGO<Game>("game");

	CVector3 diff = m_player->m_position - m_position;
	if (diff.Length() < 10.0f) {
		DeleteGO(this);
		mm_game->m_deleteClearCount++;
	}
	CVector3 diff2 = m_player2->m_position - m_position;
	if (diff2.Length() < 10.0f) {
		DeleteGO(this);
		mm_game->m_deleteClearCount++;
	}
	CVector3 diff3 = m_player3->m_position - m_position;
	if (diff3.Length() < 10.0f) {
		DeleteGO(this);
		mm_game->m_deleteClearCount++;
	}

	//���W���X�L�����f�������_���[�ɔ��f������B
	m_skinModelRender->SetPosition(m_position);
}