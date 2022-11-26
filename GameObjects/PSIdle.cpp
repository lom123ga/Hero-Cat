#include "PSIdle.h"

PSIdle::PSIdle(IPlayer* player)
{
	m_Player = player;
}

void PSIdle::Init()
{
	m_Animation = new Animation(*ASSET->getTexture("Player/idle"), sf::Vector2i(4, 1), 0.1f);
	m_Animation->setModeEndFrame(false);
}

void PSIdle::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	//scaa = -1.f; scab = 1.f;
	m_Animation->setScale(scaa, scab);
	if (m_Player->getHitBox()->getPosition().y <= DEFEAD) {

		if (!m_Player->getHitBox()->isAlive()) {
			int HP = m_Player->getHP();
			m_Player->setHP(HP - 1);
			if (HP <= 1) m_Player->changeNextState(STATE_DEATH);
			else {
				m_Player->getHitBox()->setAlive(true);
				m_Player->changeNextState(STATE_HURT);
			}
		}
		else m_Player->changeNextState(STATE_IDLE);
	}
	else {
		m_Player->setHP(0);
		m_Player->changeNextState(STATE_DEATH);
	}
	if (m_Player->getHitBox()->isAlive() && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
		float movex = 0.f;
		float movey = 0.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			m_Player->changeNextState(STATE_RUN);
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			m_Player->changeNextState(STATE_RUN);
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			m_Player->changeNextState(STATE_JUMP);
		
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			m_Player->changeNextState(STATE_ATTACK);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			m_Player->changeNextState(STATE_IDLE);
		}

	}
	else {
		//if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::STATE_DEATH);
		//else m_Player->changeNextState(STATE_IDLE);
		if (m_Player->getHitBox()->getCanFall() && m_Player->getHitBox()->isAlive()) {
			m_Player->changeNextState(STATE_FALL);
		}
		if (!m_Player->getHitBox()->isAlive()) {
			int HP = m_Player->getHP();
			if (HP <= 1) m_Player->changeNextState(STATE_DEATH);
			else {
				m_Player->setHP(HP - 1);
				m_Player->getHitBox()->setAlive(true);
				m_Player->changeNextState(STATE_HURT);
			}
		}
		else m_Player->changeNextState(STATE_IDLE);
	}

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSIdle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSIdle::Reset()
{
}
