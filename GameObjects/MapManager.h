#pragma once
#include "../GameManager/ResourceManager.h"
#include "CollisionManager.h"
#include "GrassBaseBlock.h"
#include "GroundBlock.h"
#include "WaterBlock.h"
#include "WaterFaceBlock.h"
#include "TileBlock.h"
#include "CreepBat.h"
#include "CreepRino.h"

class MapManager {
public:
	MapManager();
	~MapManager();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<GrassBaseBlock*> m_listGrassBase;
	std::list<GroundBlock*> m_listGround;
	std::list<WaterBlock*> m_listWater;
	std::list<WaterFaceBlock*> m_listWaterFace;
	std::list<TileBlock*> m_listTiles;
	std::list<CreepRino*> m_ListCreepRino;
	std::list<CreepBat*> m_ListCreepBat;
	int map_high;
	int map_weight;
};