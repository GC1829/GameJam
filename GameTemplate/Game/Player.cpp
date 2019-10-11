#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Brock.cmo");
	m_position = { 750.0f,0.0f,-200.0f };
	m_skinModelRender->SetScale({ 5.0f,10.0f,30.0f });
	m_Characon.Init(
		100.0,			 
		100.0f,			
		m_position		
	);
}

Player::~Player()
{
	DeleteGO(m_skinModelRender);
}

bool Player::Start()
{

	return true;
}

void Player::Update()
{
	if (Flag == 0) {
		if (Pad(0).IsPress(enButtonA)) {
			m_position.x = 1000.0f;
		}
		Count++;
	}
	if(Count == 30)
	{
		Flag = 1;
		Count = 0;
	}
	if (Flag == 1) {
		m_position.x = 750.0f;
		Flag = 0;
	}
	m_skinModelRender->SetPosition(m_position);
}