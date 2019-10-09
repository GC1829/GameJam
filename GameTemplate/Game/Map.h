#pragma once
class Map:public IGameObject
{
public:
	Map();
	~Map();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
};

