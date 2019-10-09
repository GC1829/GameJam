#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
}

Player::~Player()
{
}

bool Player::Start()
{

	return 0;
}

void Player::Update()
{
	if (Pad(0).IsPress(enButtonA))
	{
		m_position.x += 30.0f;
	}
	m_skinModelRender->SetPosition(m_position);
}