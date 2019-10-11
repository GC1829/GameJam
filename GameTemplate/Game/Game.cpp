#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "EnemyGenerator.h"
#include "Enemy2Generator.h"
#include "TakaraBako.h"
#include "tkEngine/light/tkDirectionLight.h"
#include <Title.h>

Game::Game()
{
	m_camera = NewGO<Camera>(0);
	m_map = NewGO<Map>(0);
	m_player = NewGO<Player>(0, "player");
	m_player2 = NewGO<Player2>(0, "player2");
	m_player3 = NewGO<Player3>(0,"player3");
	m_takarabako = NewGO<TakaraBako>(0);
	m_enemygenerator = NewGO<EnemyGenerator>(0);
	m_enemy2generator = NewGO <Enemy2Generator>(0);
}

Game::~Game()
{
	DeleteGO(m_map);
    DeleteGO(m_takarabako);
	DeleteGO(m_player);
	DeleteGO(m_player2);
	DeleteGO(m_player3);
	DeleteGO(m_spritRender);
	DeleteGO(m_skinModelRender);
	DeleteGO(m_enemy2);
	DeleteGO(m_sound);
}
bool Game::Start()
{

	//BGM再生
	m_sound = NewGO<prefab::CSoundSource>(0, "soundsource");
	m_sound->Init(L"../Assets/sound/SandSound.wav");
	//Sound->SetVolume(0.1f);
	m_sound->Play(true);

	return true;
}
void Game::Update()
{
	
	if (takarabako == 0)
	{
		//スプライトレンダーのインスタンスを作成
		m_spritRender = NewGO<prefab::CSpriteRender>(0);
		//タイトル画面のロード
		m_spritRender->Init(L"../Assets/Sprite/GAMEOVER.dds", 1280.0f, 720.0f);
		if (o == 0) {
			//サウンドのインスタンスを作成
			prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);


			//explosion.wav
			ss->Init(L"sound/8bit.wav");
			//うるさいので音を小さくする
			ss->SetVolume(1.0f);
			//ワンショット再生
			ss->Play(false);

			o = 1;
		}
		//if(o == 1){
		//	//クリアしている。時
		//	m_timer++;
		//	if (m_timer == 100) {
		//		//240フレーム経過したらタイトル画面に戻る。
		//		NewGO<Title>(0);
		//		DeleteGO(this);
		//	}
		//}
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


	if (m_clear == false) {
		//クリアしていない時
		if (m_deleteClearCount == 10) {
			m_clear = true;
			m_spritRender = NewGO<prefab::CSpriteRender>(0);
			m_spritRender->Init(L"sprite/GAMECLAER.dds",712, 65);
			////エフェクトのインスタンスの作成
			//prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			////fire.efkを再生
			//effect->Play(L"effect/fire.efk");
			////エフェクトの発生位置として敵機の座標を渡す
			//effect->SetPosition();
		}
	}

	else {
		//クリアしている。時
		m_timer++;
		if (m_timer == 200) {
			//240フレーム経過したらタイトル画面に戻る。
			NewGO<Title>(0);
			DeleteGO(this);
		}
	}
}


