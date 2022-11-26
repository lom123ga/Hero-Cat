#include "CoinManager.h"

CoinManager::CoinManager()
{
}

CoinManager::~CoinManager()
{
	for (auto it : m_ListCoins) {
		if (it != nullptr) delete it;
	}
	m_ListCoins.clear();
}

void CoinManager::Init(CollisionManager& collisionManager)
{
	int mp[20][150] = MAP;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 150; j++) {
			if (mp[i][j] == 37) {
				Coin* coin = new Coin;
				coin->Init();
				coin->getHitBox()->setAlive(true);
				coin->getHitBox()->setPosition(sf::Vector2f(j * 32 + 16, i * 32 + 16));
				coin->getHitBox()->SetTag(COIN);
				m_ListCoins.push_back(coin);
				collisionManager.addObj(coin->getHitBox());
			}
		}
	}
}

void CoinManager::Update(float deltaTime)
{
	for (auto coin : m_ListCoins) {
		coin->Update(deltaTime);
	}
}

void CoinManager::Render(sf::RenderWindow* window)
{
	for (auto coin : m_ListCoins) {
		coin->Render(window);
	}
}

int CoinManager::checkCoin()
{
	int cont = 0;
	for (auto it : m_ListCoins) {
		if (!it->getHitBox()->isAlive()) cont++;
	}
	return cont;
}
