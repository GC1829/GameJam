#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_position = { 500.0f,0.0f,0.0f };
}

Player::~Player()
{
}

bool Player::Start()
{

	return true;
}

void Player::Update()
{
	if (Pad(0).IsPress(enButtonA)) {
		m_position.x += 50.0f;
	}
	/*if (Pad(0).IsPress(enButtonUp)) {
		m_position.x -= 50.0f;
	}*/
	m_skinModelRender->SetPosition(m_position);
}