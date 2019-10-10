#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "TakaraBako.h"
#include "EnemyGenerator.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
	m_camera = NewGO<Camera>(0);
	m_map = NewGO<Map>(0);
	m_player = NewGO<Player>(0);
	//m_enemy2 = NewGO<Enemy2>(0);
	NewGO<EnemyGenerator>(0);
	m_takarabako = NewGO<TakaraBako>(0);
}

Game::~Game()
{
}
bool Game::Start()
{
	return true;
}
void Game::Update()
{

	if (takarabako == 0)
	{
		m_spritRender = NewGO<prefab::CSpriteRender>(0);
		//タイトル画面のロード
		//m_spritRender->Init(L"../Assets/Sprite/GAMEOVER.dds", 1280.0f, 720.0f);
	}
	//QueryGOs<Enemy>("enemy", [&](Enemy* enemy) {
	//	//壁に潰されたときにEnemyを消す

	//	DeleteGO(enemy);
	//	return true;
	//	});1
	//QueryGOs<Enemy>("enemy", [&](Enemy* enemy) {
	//	if (enemy == 0) {
	//		//Enemyが0になったらGameClaerを表示
	//		
			////CSpritRenderのインスタンスを作成
			//m_spritRender = NewGO<prefab::CSpriteRender>(0);
			////タイトル画面のロード
			//m_spritRender->Init(L"../Assets/sprite/GAMECLAER.dds", 500.0f, 360.0f);
	//		m_spritRender->SetPosition(position);
	//		position.x += 1.0f;
	//		position.y += 1.0f;
	//		position.z += 1.0f;

	//エフェクトのインスタンスの作成
	//prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	////再生
	//effect->Play(L"effect/");
	////エフェクトの発生位置
	//effect->SetPosition();
	//return true;
	//	}
	//	return true;
	//	});


	
	//QueryGOs<Enemy>("enemy", [&](Enemy* enemy) {
	//	//2点間の距離を計算する
	//Player* m_player = FindGO<Player>("m_player");	
	//CVector3 diff = enemy->m_position - m_position;
	////2点間の距離が～以下になったら消す
	//if (diff.Length() <= 0.0f) {
	//	takarabako = 0;
	//	DeleteGO(enemy);
	//}
	//		return true;
	//		});
	//if (takarabako == 0) {
	//	//CSpritRenderのインスタンスを作成
	//	m_spritRender = NewGO<prefab::CSpriteRender>(0);
	//	//タイトル画面のロード
	//	m_spritRender->Init(L"../Assets/Sprite/GAMEOVER.dds", 1280.0f, 720.0f);
	//}

}


