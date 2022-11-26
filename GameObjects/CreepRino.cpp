#include "CreepRino.h"

void CreepRino::Init()
{
	sca = sf::Vector2f(1.0, 1.0);
	m_HitBox = new HitBox(sf::Vector2i(20, 20));
	m_HitBox->Init(sf::Vector2f(0, 0));
	m_runAni = new Animation(*ASSET->getTexture("creep/Mushroom/Idle (32x32)"), sf::Vector2i(14, 1), 0.1f);
	m_runAni->setModeEndFrame(false);
	m_deathAni = new Animation(*ASSET->getTexture("creep/Mushroom/Hit"), sf::Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
