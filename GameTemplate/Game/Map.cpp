#include "stdafx.h"
#include "Map.h"

Map::Map()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Map.cmo");
}

Map::~Map()
{
	DeleteGO(m_skinModelRender);
}