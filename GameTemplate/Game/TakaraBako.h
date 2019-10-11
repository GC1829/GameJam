#pragma once

#include "Enemy.h"
#include "Enemy2.h"

class Game;
class TakaraBako : public IGameObject
{
public:
	TakaraBako();
	~TakaraBako();
	void Update();

	//Game* m_game = nullptr;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;
	CVector3 m_movespeed = CVector3::Zero;
};

