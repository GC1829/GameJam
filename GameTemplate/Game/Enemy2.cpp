#include "stdafx.h"
#include "Enemy2.h"
Enemy2::Enemy2()
{

}

Enemy2::~Enemy2()
{
	DeleteGO(m_skinModelRender);
}

bool Enemy2::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);

	CQuaternion qRot;
	m_skinModelRender->SetRotation(qRot);
	return true;
}

void Enemy2::Update()
{
	m_skinModelRender->SetPosition(m_position);
}