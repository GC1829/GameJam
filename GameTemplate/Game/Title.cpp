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
	//CSpritRender�̃C���X�^���X���쐬
	m_spritRender = NewGO<prefab::CSpriteRender>(0);
	//�^�C�g����ʂ̃��[�h
	m_spritRender->Init(L"../Assets/Sprit/Title.dds", 0, 0);
	return true;
}

void Title::Update()
{
	if (Pad(0).IsTrigger(enButtonStart)) {
		//�X�^�[�g�{�^���ŃQ�[���V�[���ֈړ�
		
	}
	
}