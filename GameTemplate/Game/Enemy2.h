#pragma once
class Enemy2: public IGameObject
{
public:
	Enemy2();
	~Enemy2();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
};

