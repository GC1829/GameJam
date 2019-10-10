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
	m_fontRender->SetText(L"PressAnykey");
	
	return true;
}

void Title::Update()
{
	m_fontRender->SetColor(Color);

	if (Colorjoutai == 0) {
		if (Color.x >= 0.0f) {
			Color.x -= 0.003f;
		}
		else if (Color.y >= 0.0f) {
			Color.y -= 0.003f;
		}
		else if (Color.z >= 0.0f) {
			Color.z -= 0.003f;
		}
		else {
			Colorjoutai = 1;
		}
	}
	else if (Colorjoutai == 1) {
		if (Color.x <= 1.0f) {
			Color.x += 0.003f;
		}
		else if (Color.y <= 1.0f) {
			Color.y += 0.003f;
		}
		else if (Color.z <= 1.0f) {
			Color.z += 0.003f;
		}
		else {
			Colorjoutai = 2;
		}
	}
	else if (Colorjoutai == 2) {
		if (Color.y >= 0.0f) {
			Color.y -= 0.003f;
		}
		else {
			Colorjoutai = 3;
		}
	}
	else if (Colorjoutai == 3) {
		if (Color.x >= 0.0f) {
			Color.x -= 0.003f;
		}
		else if (Color.y <= 1.0f) {
			Color.y += 0.003f;
		}
		else if (Color.z >= 0.0f) {
			Color.z -= 0.003f;
		}
		else {
			Colorjoutai = 4;
		}
	}
	else if (Colorjoutai == 4) {
		if (Color.x <= 1.0f) {
			Color.x += 0.003f;
		}
		else if (Color.z <= 1.0f) {
			Color.z += 0.003f;
		}
		else {
			Colorjoutai = 0;
		}
	}
	
	
	

	if (Pad(0).IsPressAnyKey()) {
		//スタートボタンでゲームシーンへ移動
		NewGO<Game>(0, "game");

		prefab::CSoundSource* sound = NewGO<prefab::CSoundSource>(0);
		//asioto.wav
		sound->Init(L"../Assets/sound/asioto.wav");
		//うるさいので音を小さくする
		//sound->SetVolume(0.05f);
		//ワンショット再生
		sound->Play(false);


		DeleteGO(this);
	}
	
}