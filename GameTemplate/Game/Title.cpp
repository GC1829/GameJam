#include "stdafx.h"
#include "Title.h"

Title::Title()
{
}

Title::~Title()
{
	DeleteGO(m_spritRender);
}

bool Title::Start()
{
	//CSpritRenderのインスタンスを作成
	m_spritRender = NewGO<prefab::CSpriteRender>(0);
	//タイトル画面のロード
	m_spritRender->Init(L"../Assets/Sprite/Title.dds", 1280.0f, 720.0f);
	return true;
}

void Title::Update()
{
	if (Pad(0).IsTrigger(enButtonStart)) {
		//スタートボタンでゲームシーンへ移動
		
	}
	
}