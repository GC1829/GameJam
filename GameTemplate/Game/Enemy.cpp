#include "stdafx.h"
#include "Enemy.h"

CVector3 targetPoints1[9] = {
	{-185.154f, 0.0f, -168.585f},
	{165.264f,0.0f,-167.106f},
	{157.192f,0.0f,175.868f},
	{-107.167f,0.0f,171.36f},
	{-104.21f,0.0f,-94.794f},
	{92.754f,0.0f,-97.856f},
	{92.103f,0.0f,102.487f},
	{-32.934f,0.0f,104.277f},
	{-0.25f,0.0f,6.613f}
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
	m_position = { -1000.0f, 0.0f, 1000.0f };
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale({ 5.0f, 5.0f, 5.0f });
	//�X�L�����f���ɉ�]�N�H�[�^�j�I����ݒ肷��
	CQuaternion qRot;
	m_skinModelRender->SetRotation(qRot);

	return true;
}

void Enemy::Update()
{
	//���̈ړ���Ɍ������x�N�g�����v�Z����B
	CVector3 toNext = targetPoints1[m_targetPointNo1] * 5.3f - m_position;
	if (toNext.Length() < 10.0f) {
		//���̃|�C���g�ɍs���B
		m_targetPointNo1++;
	}
	toNext.Normalize();
	m_position += toNext * 10.f;
	
	

	//Count��5�ɂȂ����痧���~�܂�
	timer += GameTime().GetFrameDeltaTime();
	if (timer > 5.0f) {
		Sleep(1 * 1000);
	}

	

	//���W���X�L�����f�������_���[�ɔ��f������B
	m_skinModelRender->SetPosition(m_position);
}
