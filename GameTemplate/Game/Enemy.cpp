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
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0, "enemy");
	//�X�L�����f�������_�[�̃��[�h
	m_skinModelRender->Init(L"");

	//�X�L�����f���ɉ�]�N�H�[�^�j�I����ݒ肷��
	CQuaternion qRot;
	m_skinModelRender->SetRotation(qRot);

	return true;
}

void Enemy::Update()
{
	//m_position.y -= 1.0f;
	//m_Count++;

	/*if (kado[0] == m_position) {
		m_position.y = 0.0f;
		
		m_position.x += 1.0f;
		qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
	}*/
	
	

	/*if (m_Count == 6) {

		m_position.x = 0;
		m_position.y = 0;
		m_position.z = 0;

		m_timer += GameTime().GetFrameDeltaTime();
		switch(m_timer > 1.5f) {

		default:
		m_Count = 0
			break;
		}

	}*/

	//���W���X�L�����f�������_���[�ɔ��f������B
	m_skinModelRender->SetPosition(m_position);
}