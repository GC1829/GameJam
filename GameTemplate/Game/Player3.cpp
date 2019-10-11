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
	if (Pad(0).IsPress(enButtonB)) {
		m_position.z += 50.0f;
	}
	if (Pad(0).IsPress(enButtonY)) {
		m_position.z -= 50.0f;
	}
	m_skinModelRender->SetPosition(m_position);
}