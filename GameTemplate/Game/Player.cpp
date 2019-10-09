#include "stdafx.h"
#include "Player.h"

Player::Player()
{

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
	if (Pad(0).IsPress(enButtonUp)) {
		m_position.x += 100.0f;
	}
}