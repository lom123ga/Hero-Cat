#include "PSAttack.h"

PSAttack::PSAttack(IPlayer* player)
{
	m_Player = player;
	numFrame = 18;
	contFrame = 0;
}

void PSAttack::Init()
{
	m_Animation = new Animation(*ASSET->getTexture("Player/attack"), sf::Vector2i(4, 1), 0.1f);
	m_Animation->setModeEndFrame(false);
}

void PSAttack::Update(float deltaTime)
{
	if (contFrame == numFrame) contFrame = 0;
	contFrame += 1;
	m_Animation->Update(deltaTime);
	m_Player->getHitBox()->setAttack(true);
	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::STATE_DEATH);

	//scaa = -1.f; scab = 1.f;
	m_Animation->setScale(scaa, scab);

	if (m_Player->getHitBox()->getCanFall() && m_Player->getHitBox()->isAlive()) {
		m_Player->changeNextState(STATE_FALL);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_Player->changeNextState(STATE_RUN);
	}
	if (m_Player->getHitBox()->getCanJump() && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_Player->changeNextState(STATE_JUMP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		m_Player->changeNextState(STATE_IDLE);
	}
	if (contFrame == numFrame) {
		contFrame = 0;
		m_Player->changeNextState(STATE_IDLE);
	}

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSAttack::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSAttack::Reset()
{
	m_Animation->Reset();
}
