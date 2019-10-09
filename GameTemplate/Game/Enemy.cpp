#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	DeleteGO(m_skinModelRender);
}

bool Enemy::Start()
{
	//�X�L�����f�������_�[�̃C���X�^���X�̍쐬
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0, "enemy2");
	//�X�L�����f�������_�[�̃��[�h
	//m_skinModelRender->Init(L"");

	//�X�L�����f���ɉ�]�N�H�[�^�j�I����ݒ肷��
	CQuaternion qRot;
	m_skinModelRender->SetRotation(qRot);

	return true;
}

void Enemy::Update()
{
	/*if (kado[0] == m_position) {
		m_moveSpeed.y = 0.0f;
		
		m_moveSpeed.x += 1.0f;
		qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
	}*/

	m_moveSpeed.y += 1.0f;
}