#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Camera.h"

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	Camera* m_camera = nullptr;
	Map* m_map = nullptr;
	Player* m_player = nullptr;
	Enemy2* m_enemy2 = nullptr;
	Enemy* enemy = nullptr;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。

	prefab::CSpriteRender* m_spritRender = nullptr;
	CVector3 position = {0, 0, 0};

	int takarabako = 1;
};

