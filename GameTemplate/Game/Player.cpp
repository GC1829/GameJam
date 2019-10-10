#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	/*m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");*/
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
	m_position = { 500.0f,0.0f,300.0f };
	m_skinModelRender->SetPosition(m_position);
}