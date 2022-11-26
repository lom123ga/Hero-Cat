#include "GSIntro.h"

GSIntro::GSIntro()
{
	m_currentTime = 0.f;
}

GSIntro::~GSIntro()
{
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	sf::Texture* texture = ASSET->getTexture("./intro");
	m_intro.setTexture(*texture);

	m_intro.setPosition(screenWidth / 2, screenHeight / 2);
	m_intro.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_intro.setScale(1.f * screenWidth / m_intro.getTexture()->getSize().x, 1.f * screenHeight / m_intro.getTexture()->getSize().y);
}

void GSIntro::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime > 1.f) {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->draw(m_intro);
}
