#pragma once

#include "Player.h"
#include "Player2.h"
#include "Player3.h"
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();

	bool Start();
	void Update();
	Player* m_player;
	Player2* m_player2;
	Player3* m_player3;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	//スキンモデルレンダー
	CVector3 m_position = CVector3::Zero;

	CVector3 m_moveSpeed = CVector3::Zero;
	//移動速度

	CQuaternion rotation = CQuaternion::Identity;

	int m_targetPointNo1 = 0;
	
	int Count = 0;
	int Count2 = 0;
	int timer = 0;
	int state = 0;
};

