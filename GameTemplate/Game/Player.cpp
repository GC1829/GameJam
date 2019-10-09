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

}