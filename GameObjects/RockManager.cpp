#include "RockManager.h"

RockManager::RockManager()
{
}

RockManager::~RockManager()
{
	if (m_Rock != nullptr) delete m_Rock;
}

void RockManager::Init(CollisionManager& collisionManager)
{
	m_Rock = new Rock;
	m_Rock->Init();
	m_Rock->getHitbox()->setAlive(false);
	collisionManager.addObj(m_Rock->getHitbox());
}

void RockManager::Update(float deltaTime)
{
	m_Rock->Update(deltaTime);
}

void RockManager::Render(sf::RenderWindow* window)
{
	m_Rock->Render(window);
}

Rock* RockManager::SpawnRock()
{
	if (m_Rock->getHitbox()->isAlive() == false) return m_Rock;
	return nullptr;
}
