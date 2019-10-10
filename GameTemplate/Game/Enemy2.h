#pragma once

#include "Player.h"
#include "Player2.h"
#include "Player3.h"
class Enemy2: public IGameObject
{
public:
	Enemy2();
	~Enemy2();

	bool Start();
	void Update();

	Player* m_player = nullptr;
	Player2* m_player2 = nullptr;
	Player3* m_player3 = nullptr;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion rotation = CQuaternion::Identity;
	int m_targetPointNo = 0;
};

