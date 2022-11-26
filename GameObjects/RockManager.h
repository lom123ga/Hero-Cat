#pragma once
#include "../GameManager/ResourceManager.h"
#include "CollisionManager.h"
#include "Rock.h"

class RockManager {
public:
	RockManager();
	~RockManager();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	Rock* SpawnRock();
private:
	Rock* m_Rock;
};