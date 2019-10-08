#pragma once
class Camera : public IGameObject
{
public:
	Camera();
	~Camera();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
};