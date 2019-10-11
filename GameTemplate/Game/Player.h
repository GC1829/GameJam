#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::Zero;
	CVector3 m_movespeed = CVector3::Zero;
	CCharacterController m_Characon;

	int Count = 0;
};

