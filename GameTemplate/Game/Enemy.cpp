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
	//壁にぶつかったら方向転換する+時々止まるエネミー
	//スキンモデルレンダーのインスタンスの作成
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0, "enemy");
	//スキンモデルレンダーのロード
	m_skinModelRender->Init(L"../Assets/modelData/Enemy1.cmo");
	m_skinModelRender->SetScale({ 10.0f, 10.0f, 10.0f });
	//スキンモデルに回転クォータニオンを設定する
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
		//動いているとき
		//次の移動先に向かうベクトルを計算する。
		CVector3 toNext = targetPoints1[m_targetPointNo1] * 5.3f - m_position;
		if (toNext.Length() < 10.0f) {
			//次のポイントに行く。
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
		//止まっているとき
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

	//座標をスキンモデルレンダラーに反映させる。
	m_skinModelRender->SetPosition(m_position);
}