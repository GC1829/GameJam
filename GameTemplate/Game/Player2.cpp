#include "stdafx.h"
#include "Player2.h"

Player2::Player2()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Brock.cmo");
	m_position = { 0.0f,0.0f,-1100.0f };
	m_skinModelRender->SetScale({15.0f,10.0f,5.0f });
	m_Characon.Init(
		20.0,
		100.0f,
		m_position
	);
}

Player2::~Player2()
{
}

bool Player2::Start()
{

	return true;
}

void Player2::Update()
{
	if (Pad(0).IsPress(enButtonX)) {
		m_position.z += 20.0f;
	}
	/*if (Pad(0).IsPress(enButtonUp)) {
		m_position.x -= 50.0f;
	}*/
	m_skinModelRender->SetPosition(m_position);
}