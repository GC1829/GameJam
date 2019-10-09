#pragma once
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	//スキンモデルレンダー
	CVector3 m_position = CVector3::Zero;

	CVector3 m_moveSpeed = CVector3::Zero;
	//移動速度

	int m_targetPointNo1 = 0;
	
	int Count = 0;
	int timer = 0;
};

