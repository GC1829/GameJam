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
	m_position.x += Pad(0).GetLStickXF() * -150.0f;
	m_skinModelRender->SetPosition(m_position);
}