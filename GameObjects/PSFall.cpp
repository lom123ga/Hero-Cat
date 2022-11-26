#include "PSFall.h"

PSFall::PSFall(IPlayer* player)
{
	m_Player = player;
	m_currentTime = 0.f;
}

void PSFall::Init()
{
	m_Animation = new Animation(*ASSET->getTexture("Player/fall"), sf::Vector2i(4, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void PSFall::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	//if (m_Player->getHitBox()->getCanFall()) {
		if (m_currentTime <= 0.5f) m_currentTime += deltaTime;
		float v = 10 * m_currentTime;
		m_Player->getHitBox()->move(0, v);
	if (m_Player->getHitBox()->getPosition().y <= DEFEAD) {
		if (!m_Player->getHitBox()->isAlive()) {
			int HP = m_Player->getHP();
			m_Player->setHP(HP - 1);
			if (HP <= 1) m_Player->changeNextState(STATE_DEATH);
			else {
				m_Player->getHitBox()->setAlive(true);
				m_Player->changeNextState(STATE_FALL2);
			}
		}
		else {
			if (!m_Player->getHitBox()->getCanFall()) {
				m_currentTime = 0.f;
				m_Player->changeNextState(STATE_IDLE);
			}
			//else m_Player->changeNextState(STATE_FALL);
		}
	}
	else {
		m_Player->setHP(0);
		m_Player->changeNextState(STATE_DEATH);
	}
	if (m_Player->getHitBox()->isAlive()) {
		if (m_Player->getHitBox()->getCanL() && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			scaa = -1.f; scab = 1.f;
			m_Animation->setScale(scaa, scab);
			m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		}
		else if (m_Player->getHitBox()->getCanR() && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			scaa = 1.f; scab = 1.f;
			m_Animation->setScale(scaa, scab);
			m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		}else if (m_Player->getHitBox()->getCanJump() && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			m_Player->changeNextState(STATE_JUMP2);
		}
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSFall::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSFall::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
