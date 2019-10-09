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
	//スキンモデルレンダーのインスタンスの作成
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0, "enemy2");
	//スキンモデルレンダーのロード
	//m_skinModelRender->Init(L"");

	//スキンモデルに回転クォータニオンを設定する
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