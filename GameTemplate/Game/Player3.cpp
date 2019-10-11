#include "stdafx.h"
#include "Player3.h"

Player3::Player3()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Brock.cmo");
	m_position = { 200.0f,0.0f,600.0f };
	m_skinModelRender->SetScale({ 10.0f,10.0f,10.0f });
	m_Characon.Init(
		100.0,
		100.0f,
		m_position
	);
}

Player3::~Player3()
{
	DeleteGO(m_skinModelRender);
}

bool Player3::Start()
{

	return true;
}

void Player3::Update()
{
	if (Flag == 0) {
		if (Pad(0).IsPress(enButtonB)) {
			m_position.z = 900.0f;
		}
		Count++;
	}
	if (Count == 30)
	{
		Flag = 1;
		Count = 0;
	}
	if (Flag == 1) {
		m_position.z = 600.0f;
		Flag = 0;
	}
	m_skinModelRender->SetPosition(m_position);
}