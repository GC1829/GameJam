#pragma once
class Title:public IGameObject
{
public:
	Title();
	~Title();

	bool Start();
	void Update();
	

	prefab::CSpriteRender* m_spritRender = nullptr;
	prefab::CFontRender* m_fontRender = nullptr;
	
	CVector3 Color = { 1.0f, 1.0f, 1.0f };
	int Colorjoutai = 0;

	float scale = 1.0f;
	int j_scale = 0;
	
	
	
};

