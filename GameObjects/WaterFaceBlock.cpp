#include "WaterFaceBlock.h"

void WaterFaceBlock::Init()
{

	m_HitBox = new HitBox(sf::Vector2i(12, 32));
	m_HitBox->Init(sf::Vector2f(0, 0));
	m_Block = new Animation(*ASSET->getTexture("map/waterface"), sf::Vector2i(1, 1), 0.1f);
	m_HitBox->SetTag(MAPBLOCK);
}
