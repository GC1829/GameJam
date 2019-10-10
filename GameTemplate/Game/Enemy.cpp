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
	//壁にぶつかったら方向転換する+時々止まるエネミー
	//スキンモデルレンダーのインスタンスの作成
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0, "enemy");
	//スキンモデルレンダーのロード
	m_skinModelRender->Init(L"../Assets/modelData/Enemy1.cmo");
	m_position = { -1000.0f, 0.0f, 1000.0f };
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale({ 5.0f, 5.0f, 5.0f });
	//スキンモデルに回転クォータニオンを設定する
	CQuaternion qRot;
	m_skinModelRender->SetRotation(qRot);

	return true;
}

void Enemy::Update()
{
	//次の移動先に向かうベクトルを計算する。
	CVector3 toNext = targetPoints1[m_targetPointNo1] * 5.3f - m_position;
	if (toNext.Length() < 10.0f) {
		//次のポイントに行く。
		m_targetPointNo1++;
	}
	toNext.Normalize();
	m_position += toNext * 10.f;
	
	

	//Countが5になったら立ち止まる
	timer += GameTime().GetFrameDeltaTime();
	if (timer > 5.0f) {
		Sleep(1 * 1000);
	}

	

	//座標をスキンモデルレンダラーに反映させる。
	m_skinModelRender->SetPosition(m_position);
}
