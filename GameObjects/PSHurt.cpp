#include "PSHurt.h"

PSHurt::PSHurt(IPlayer* player)
{
	m_Player = player;
	m_timeRemain = 0.5f;
}

void PSHurt::Init()
{
	m_Animation = new Animation(*ASSET->getTexture("Player/hurt"), sf::Vector2i(4, 1), 0.1f);
	m_Animation->setModeEndFrame(false);
}

void PSHurt::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= m_timeRemain) {
		m_Player->changeNextState(STATE_IDLE);
	}
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSHurt::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSHurt::Reset()
{
}
