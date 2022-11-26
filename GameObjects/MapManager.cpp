#include "MapManager.h"

MapManager::MapManager()
{
	map_high = 20;
	map_weight = 50;
}

MapManager::~MapManager()
{
	for (auto it : m_listGrassBase) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listGrassBase.clear();
	for (auto it : m_listGround) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listGround.clear();
	for (auto it : m_listWater) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listWater.clear();
	for (auto it : m_listWaterFace) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listWaterFace.clear();
	for (auto it : m_listTiles) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listTiles.clear();
	for (auto it : m_ListCreepRino) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_ListCreepRino.clear();
	for (auto it : m_ListCreepBat) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_ListCreepBat.clear();
}

void MapManager::Init(CollisionManager& collisionManager)
{
	int mp[20][150] = MAP;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 150; j++) {
			if (mp[i][j] == 1) {
				TileBlock* map1 = new TileBlock();
				map1->Init();
				map1->getHitBox()->setAlive(true);
				map1->getHitBox()->setPosition(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				map1->getHitBox()->SetTag(MAPBLOCK);
				m_listTiles.push_back(map1);
				collisionManager.addObj(map1->getHitBox());
			}
			else if (mp[i][j] == 3) {
				GrassBaseBlock* map2 = new GrassBaseBlock();
				map2->Init();
				map2->getHitBox()->setAlive(true);
				map2->getHitBox()->setPosition(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				map2->getHitBox()->SetTag(MAPBLOCK);
				m_listGrassBase.push_back(map2);
				collisionManager.addObj(map2->getHitBox());
			}
			else if (mp[i][j] == 10) {
				GroundBlock* map3 = new GroundBlock();
				map3->Init();
				map3->getHitBox()->setAlive(true);
				map3->getHitBox()->setPosition(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				map3->getHitBox()->SetTag(MAPBLOCK);
				m_listGround.push_back(map3);
				collisionManager.addObj(map3->getHitBox());
			}
			else if (mp[i][j] == 28) {
				WaterFaceBlock* map4 = new WaterFaceBlock();
				map4->Init();
				map4->getHitBox()->setAlive(true);
				map4->getHitBox()->setPosition(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				map4->getHitBox()->SetTag(CREEP);
				m_listWaterFace.push_back(map4);
				collisionManager.addObj(map4->getHitBox());
			}
			else if (mp[i][j] == 35) {
				WaterBlock* map5 = new WaterBlock();
				map5->Init();
				map5->getHitBox()->setAlive(true);
				map5->getHitBox()->setPosition(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				//map5->getHitBox()->SetTag();
				m_listWater.push_back(map5);
				//collisionManager.addObj(map5->getHitBox());
			}
			else if (mp[i][j] == 11) {
				GroundBlock* map6 = new GroundBlock();
				map6->Init();
				map6->getHitBox()->setAlive(true);
				map6->getHitBox()->setPosition(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				//map3->getHitBox()->SetTag(MAPBLOCK);
				m_listGround.push_back(map6);
				//collisionManager.addObj(map3->getHitBox());
			}
			else if (mp[i][j] == 36) {
				CreepRino* map7 = new CreepRino();
				map7->Init();
				map7->getHitBox()->setAlive(true);
				map7->getHitBox()->setPosition(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				map7->setStartPoint(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				map7->getHitBox()->SetTag(CREEP);
				m_ListCreepRino.push_back(map7);
				collisionManager.addObj(map7->getHitBox());
			}
			else if (mp[i][j] == 29) {
				CreepBat* map8 = new CreepBat();
				map8->Init();
				map8->getHitBox()->setAlive(true);
				map8->getHitBox()->setPosition(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				map8->setStartPoint(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				map8->getHitBox()->SetTag(CREEP);
				map8->setTime(2.0f);
				m_ListCreepBat.push_back(map8);
				collisionManager.addObj(map8->getHitBox());
			}
		}
	}
}

void MapManager::Update(float deltaTime)
{
	for (auto map : m_listTiles) {
		map->Update(deltaTime);
	}
	for (auto map : m_listGrassBase) {
		map->Update(deltaTime);
	}
	for (auto map : m_listGround) {
		map->Update(deltaTime);
	}
	for (auto map : m_listWaterFace) {
		map->Update(deltaTime);
	}
	for (auto map : m_listWater) {
		map->Update(deltaTime);
	}
	for (auto creep : m_ListCreepBat) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_ListCreepRino) {
		creep->Update(deltaTime);
	}
}

void MapManager::Render(sf::RenderWindow* window)
{
	for (auto map : m_listGrassBase) {
		map->Render(window);
	}
	for (auto map : m_listGround) {
		map->Render(window);
	}
	for (auto map : m_listWater) {
		map->Render(window);
	}
	for (auto map : m_listWaterFace) {
		map->Render(window);
	}
	for (auto map : m_listTiles) {
		map->Render(window);
	}
	for (auto creep : m_ListCreepBat) {
		if (creep->getHitBox()->isAlive()) creep->Render(window);
	}
	for (auto creep : m_ListCreepRino) {
		if (creep->getHitBox()->isAlive()) creep->Render(window);
	}
}
