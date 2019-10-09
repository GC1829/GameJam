#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
	m_camera = NewGO<Camera>(0);
	m_map = NewGO<Map>(0);
}

Game::~Game()
{
}
bool Game::Start()
{
	return 0;
}
void Game::Update()
{
}