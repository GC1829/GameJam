#include "stdafx.h"
#include "Map.h"

Map::Map()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Map.cmo");
	m_PS.CreateMesh(CVector3::Zero, CQuaternion::Identity, CVector3::One, m_skinModelRender);
}

Map::~Map()
{
	DeleteGO(m_skinModelRender);
}