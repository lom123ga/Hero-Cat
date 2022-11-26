#pragma once
#include "../GameManager/ResourceManager.h"
#include "Coin.h"
#include "CollisionManager.h"

class CoinManager {
public:
	CoinManager();
	~CoinManager();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	int checkCoin();
private:
	std::list<Coin*> m_ListCoins;
};