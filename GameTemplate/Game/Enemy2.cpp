#include "stdafx.h"
#include "Enemy2.h"
#include "Player.h"
#include "Player2.h"
#include "Player3.h"

CVector3 targetPoints[9] = {
	{-195.300f, 0.0f, -195.000f},
	{193.000f,0.0f,-188.000f},
	{193.000f,0.0f,195.000f},
	{-107.167f,0.0f,171.36f},
	{-104.21f,0.0f,-150.000f},
	{92.754f,0.0f,-150.000f},
	{92.103f,0.0f,102.487f},
	{-25.934f,0.0f,104.277f},
	{-0.25f,0.0f,-10.000f},

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
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0, "enemy2");
	m_skinModelRender->Init(L"modelData/Enemy2.cmo");
	m_position = { -1000.0f, 0.0f, 1400.0f };
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale({ 10.0f, 10.0f, 10.0f });
	//m_skinModelRender->m_position.x = -185.154f;
	//m_skinModelRender->m_position.y = 207.712f;
	//m_skinModelRender->m_position.z = 0.0f;

	CQuaternion qRot;
	m_skinModelRender->SetRotation(qRot);
	m_player = FindGO<Player>("player");
	m_player2 = FindGO<Player2>("player2");
	m_player3 = FindGO<Player3>("player3");
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
	CVector3 diff = m_player->m_position - m_position;
	if (diff.Length() < 10.0f) {
		DeleteGO(this);
	}
	CVector3 diff2 = m_player2->m_position - m_position;
	if (diff2.Length() < 10.0f) {
		DeleteGO(this);
	}
	CVector3 diff3 = m_player3->m_position - m_position;
	if (diff3.Length() < 10.0f) {
		DeleteGO(this);
	}
	
	m_skinModelRender->SetPosition(m_position);
}