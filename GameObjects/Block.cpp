#include "Block.h"

Block::Block()
{
}

Block::~Block()
{
	if (m_HitBox != nullptr) delete m_HitBox;
	if (m_Block != nullptr) delete m_Block;
}

void Block::Init()
{
}

void Block::Update(float deltaTime)
{
	m_Block->Update(deltaTime);
	m_Block->setPosition(getHitBox()->getPosition());
}

void Block::Render(sf::RenderWindow* window)
{
	window->draw(*m_Block);
	//window->draw(*m_HitBox);
}

void Block::Reset()
{
	m_Block->Reset();
}
