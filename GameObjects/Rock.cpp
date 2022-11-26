#include "Rock.h"

Rock::Rock()
{
}

Rock::~Rock()
{
	if (m_Animation != nullptr) delete m_Animation;
	if (m_Hitbox != nullptr) delete m_Hitbox;
}

void Rock::Init()
{
	m_currentTime = 0;
	m_Animation = new Animation(*ASSET->getTexture("Player/Rock2"), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
	m_Hitbox = new HitBox(sf::Vector2i(16, 16));
	m_Hitbox->Init(sf::Vector2f(450, 0));
	m_Hitbox->SetTag(ROCK);
	m_Hitbox->setAlive(false);
	aac = 1;
}

void Rock::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime > 1) m_Hitbox->setAlive(false);
	if (!m_Hitbox->isAlive()) {
		Reset();
		return;
	}
	m_Hitbox->move(m_Hitbox->getVelocity().x * aac *deltaTime,0 );
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Hitbox->getPosition());
}

void Rock::Render(sf::RenderWindow* window)
{
	if (m_Hitbox->isAlive()) {
		window->draw(*m_Animation);
	}
}

void Rock::Reset()
{
	m_currentTime = 0.f;
	aac = 1;
}

void Rock::setStartPoint(sf::Vector2f point)
{
	m_Hitbox->setPosition(point);
	m_Animation->setPosition(point);
}
