#include "stdafx.h"
#include "Player2.h"

Player2::Player2()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Brock.cmo");
	m_position = { 0.0f,0.0f,-1200.0f };
	m_skinModelRender->SetScale({15.0f,10.0f,5.0f });
	m_Characon.Init(
		100.0,
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
	if (Flag == 0) {
		if (Pad(0).IsPress(enButtonX)) {
			m_position.z = -1100.0f;
		}
		Count++;
	}
	if (Count == 30)
	{
		Flag = 1;
		Count = 0;
	}
	if (Flag == 1) {
		m_position.z = -1200.0f;
		Flag = 0;
	}
	m_skinModelRender->SetPosition(m_position);
}