#include "CreepBat.h"

void CreepBat::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(20, 20));
	m_HitBox->Init(sf::Vector2f(100, 0));
	sca = sf::Vector2f(0.5, 0.5);
	m_runAni = new Animation(*ASSET->getTexture("creep/Bat/Flying (46x30)"), sf::Vector2i(7, 1), 0.1f);
	m_runAni->setModeEndFrame(false);
	m_runAni->setScale(0.5f,0.5f);
	m_deathAni = new Animation(*ASSET->getTexture("creep/Bat/Hit (46x30)"), sf::Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_deathAni->setScale(0.5f, 0.5f);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
