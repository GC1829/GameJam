#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{
}

Title::~Title()
{
	DeleteGO(m_spritRender);
	DeleteGO(m_fontRender);
}

bool Title::Start()
{

	//CSpritRenderのインスタンスを作成
	m_spritRender = NewGO<prefab::CSpriteRender>(0);
	//タイトル画面のロード
	m_spritRender->Init(L"../Assets/Sprite/Title.dds", 1280.0f, 720.0f);
	
	//CFontRenderのインスタンスを作成
	m_fontRender = NewGO<prefab::CFontRender>(0, "Font");
	//Fontのロード
	m_fontRender->SetText(L"Press Start Button");

	return true;
}

void Title::Update()
{
	if (Pad(0).IsTrigger(enButtonStart)) {
		//スタートボタンでゲームシーンへ移動
		NewGO<Game>(0, "game");


		DeleteGO(this);
	}
	
}