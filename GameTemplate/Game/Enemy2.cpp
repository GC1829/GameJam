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
	//壁にぶつかったら方向転換するだけのエネミー
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0,"enemy2");
	m_skinModelRender->Init(L"modelData/Enemy2.cmo");

	CQuaternion qRot;
	m_skinModelRender->SetRotation(qRot);
	return true;
}

void Enemy2::Update()
{
	m_skinModelRender->SetPosition(m_position);
}