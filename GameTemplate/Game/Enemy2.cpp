#include "stdafx.h"
#include "Enemy2.h"

CVector3 targetPoints[9] = {
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
Enemy2::Enemy2()
{
	
}

Enemy2::~Enemy2()
{
	DeleteGO(m_skinModelRender);
}

bool Enemy2::Start()
{
	//壁にぶつかったら方向転換するだけのエネミー
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0, "enemy1");
	m_skinModelRender->Init(L"modelData/Enemy2.cmo");
	m_position = { -1000.0f, 0.0f, 1000.0f };
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale({ 5.0f, 5.0f, 5.0f });
	//m_skinModelRender->m_position.x = -185.154f;
	//m_skinModelRender->m_position.y = 207.712f;
	//m_skinModelRender->m_position.z = 0.0f;
	//m_position.x = -185.154f;
	//m_position.y = 207.712f;
	//m_position.z = 0.0f;
	//m_skinModelRender->SetPosition(m_position);
	CQuaternion qRot;
	m_skinModelRender->SetRotation(qRot);
	return true;
}

void Enemy2::Update()
{
	//次の移動先に向かうベクトルを計算する。
	CVector3 toNext = targetPoints[m_targetPointNo] *5.3f - m_position;
	if (toNext.Length() < 10.0f) {
		//次のポイントに行く。
		m_targetPointNo++;
	}
	toNext.Normalize();
	m_position += toNext * 10.f;

	
	m_skinModelRender->SetPosition(m_position);
}