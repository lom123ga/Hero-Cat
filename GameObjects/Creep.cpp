#include "Creep.h"

Creep::Creep()
{
	m_stop = true;
	m_soundDeadisPlay = false;
	m_currentTime = 0;
	sca = sf::Vector2f(1.0,1.0);
	m_time = 0.2f;
}

Creep::~Creep()
{
	m_currentAni = nullptr;
	if (m_deathAni != nullptr) {
		delete m_deathAni;
	}
	if (m_runAni != nullptr) {
		delete m_runAni;
	}
	if (m_HitBox != nullptr) {
		delete m_HitBox;
	}
}

void Creep::Init()
{
}

void Creep::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_HitBox->isAlive()) {
		if (m_currentTime > m_time) {
			m_currentTime = 0;
			sca.x *= -1;
		}
		m_HitBox->move(m_HitBox->getVelocity().x * sca.x * deltaTime,0);
		m_currentAni->Update(deltaTime);
		m_currentAni->setScale(-sca.x,sca.y);
		m_currentAni->setPosition(getHitBox()->getPosition());
	}
	else
	{
		m_currentAni = m_deathAni;
		if (m_currentAni->getCurrentFrame().x != m_currentAni->getFrameNum().x - 1) {
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(getHitBox()->getPosition());
		}
		else m_stop = true;

	}
}

void Creep::Render(sf::RenderWindow* window)
{
	window->draw(*m_currentAni);
	//window->draw(*m_HitBox);
}

void Creep::Reset()
{
	m_deathAni->Reset();
	m_runAni->Reset();
	m_currentAni = m_runAni;
}
