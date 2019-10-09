#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Camera.h"
#include "Player.h"

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	Camera* m_camera = nullptr;
	Player* m_player = nullptr;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
};

