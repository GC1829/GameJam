#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Camera.h"

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Player2.h"
#include "Player3.h"
#include "TakaraBako.h"
#include "Enemy2Generator.h"
#include "EnemyGenerator.h"
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
	Player2* m_player2 = nullptr;
	Player3* m_player3 = nullptr;
	Enemy2* m_enemy2 = nullptr;
	Enemy* m_enemy = nullptr;
	TakaraBako* m_takarabako = nullptr;
	EnemyGenerator* m_enemygenerator = nullptr;
	Enemy2Generator* m_enemy2generator = nullptr;
	int m_deleteClearCount = 0;
	bool m_clear = false;
	int m_timer = 0;
	

	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。

	prefab::CSpriteRender* m_spritRender = nullptr;
	CVector3 position = {0, 0, 0};

	int takarabako = 1;
};

