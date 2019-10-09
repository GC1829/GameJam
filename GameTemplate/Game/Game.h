#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Camera.h"


class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	Camera* m_camera = nullptr;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。

	prefab::CSpriteRender* m_spritRender = nullptr;
};

