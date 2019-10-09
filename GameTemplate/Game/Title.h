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
};

