#include "stdafx.h"
#include "TakaraBako.h"
#include "Game.h"

TakaraBako::TakaraBako()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	//m_game = FindGO<Game>("Game");
}

TakaraBako::~TakaraBako()
{

}

void TakaraBako::Update()
{
	//CVector3 diff = m_enemy->m_position - m_position;
	//CVector3 diff2 = m_enemy2->m_position - m_position;
	//if (diff.Length() < 100.0f /*&& diff2.Length() < 100.0f*/) {
	//	
	//	m_game->takarabako--;
	//}

	QueryGOs<Game>("Game", [&](Game* game)->bool {
		CVector3 diff = m_enemy->m_position - m_position;
		if (diff.Length() < 100.0f /*&& diff2.Length() < 100.0f*/) {

			m_game->takarabako--;
		}
		return true;
		});
}