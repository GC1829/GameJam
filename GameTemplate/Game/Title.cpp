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

	//CSpritRender�̃C���X�^���X���쐬
	m_spritRender = NewGO<prefab::CSpriteRender>(0);
	//�^�C�g����ʂ̃��[�h
	m_spritRender->Init(L"../Assets/Sprite/Title.dds", 1280.0f, 720.0f);
	
	//CFontRender�̃C���X�^���X���쐬
	m_fontRender = NewGO<prefab::CFontRender>(0, "Font");
	//Font�̃��[�h
	m_fontRender->SetText(L"Press Start Button");


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
	
	

	if (Pad(0).IsPressAnyKey()) {
		//�X�^�[�g�{�^���ŃQ�[���V�[���ֈړ�
		NewGO<Game>(0, "game");


		DeleteGO(this);
	}
	
}