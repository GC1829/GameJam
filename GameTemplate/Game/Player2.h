#pragma once
class Player2 : public IGameObject
{
public:
	Player2();
	~Player2();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::Zero;
	CVector3 m_movespeed = CVector3::Zero;
	CCharacterController m_Characon;
	int Flag = 0;
	int Count = 0;
};


