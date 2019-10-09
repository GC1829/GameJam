#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"

#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
	m_camera = NewGO<Camera>(0);
	m_map = NewGO<Map>(0);
	//m_player = NewGO<Player>(0);
	m_enemy2 = NewGO<Enemy2>(0);
}

Game::~Game()
{
}
bool Game::Start()
{
	//NewGO<Enemy>(0, "enemy");
	return 0;
}
void Game::Update()
{
	QueryGOs<Enemy>("enemy", [&](Enemy* enemy) {
		//壁に潰されたときにEnemyを消す

		DeleteGO(enemy);
		return true;
		});
	QueryGOs<Enemy>("enemy", [&](Enemy* enemy) {
		if (enemy == 0) {
			//Enemyが0になったらGameClaerを表示
			
			//CSpritRenderのインスタンスを作成
			m_spritRender = NewGO<prefab::CSpriteRender>(0);
			//タイトル画面のロード
			m_spritRender->Init(L"", 1280.0f, 720.0f);
			return true;
		}
		return true;
		});

}