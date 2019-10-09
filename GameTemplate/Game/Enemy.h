#pragma once
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	//�X�L�����f�������_�[
	CVector3 m_position = CVector3::Zero;

	CVector3 m_moveSpeed = CVector3::Zero;
	//�ړ����x

	//�^�C�}�[
	int m_timer = 0;
	
	int m_Count = 0;

	//CVector3 kado = {0, 0, 0};
};

