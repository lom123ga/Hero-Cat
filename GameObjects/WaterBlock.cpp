#include "WaterBlock.h"

void WaterBlock::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(32, 32));
	m_HitBox->Init(sf::Vector2f(0, 0));
	m_Block = new Animation(*ASSET->getTexture("map/water"), sf::Vector2i(1, 1), 0.1f);
	m_HitBox->SetTag(MAPBLOCK);
}
