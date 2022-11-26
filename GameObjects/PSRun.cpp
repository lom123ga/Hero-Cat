#include "PSRun.h"

PSRun::PSRun(IPlayer* player)
{
	m_Player = player;
}

void PSRun::Init()
{
	m_Animation = new Animation(*ASSET->getTexture("Player/run"), sf::Vector2i(6, 1), 0.1f);
	m_Animation->setModeEndFrame(false);
}

void PSRun::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	if (m_Player->getHitBox()->getCanFall()) {
		m_Player->changeNextState(STATE_FALL);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		float movex = 0.f;
		float movey = 0.f;
		if (m_Player->getHitBox()->getCanL() && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			scaa = -1.f; scab = 1.f;
			m_Animation->setScale(scaa, scab);
			movex = -m_Player->getHitBox()->getVelocity().x * deltaTime;
			movey = 0.f;
			m_Player->getHitBox()->move(movex, movey);
		}
		if (m_Player->getHitBox()->getCanR() && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			scaa = 1.f; scab = 1.f;
			m_Animation->setScale(scaa, scab);
			movex = m_Player->getHitBox()->getVelocity().x * deltaTime;
			movey = 0.f;
			m_Player->getHitBox()->move(movex, movey);
		}
		if (m_Player->getHitBox()->getCanJump() && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			m_Player->changeNextState(STATE_JUMP);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			m_Player->changeNextState(STATE_IDLE);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			m_Player->changeNextState(STATE_ATTACK);
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

void PSRun::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSRun::Reset()
{
	m_Animation->Reset();
}
