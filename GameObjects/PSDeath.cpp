#include "PSDeath.h"

PSDeath::PSDeath(IPlayer* player)
{
	m_Player = player;
	m_timeRemain = 4.f;
	m_text = new sf::Text;
}

void PSDeath::Init()
{
	m_Animation = new Animation(*ASSET->getTexture("Player/death"), sf::Vector2i(8, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
	m_text = new sf::Text;
	m_text->setFont(*ASSET->getFont("H1"));
	m_text->setString("GAME OVER :D");
	m_text->setFillColor(sf::Color::Red);
	m_text->setPosition(sf::Vector2f(screenWidth/2 - 50,screenHeight/2- screenHeight/4));
	m_text->setScale(2.0, 2.0);
	/*m_score = new sf::Text;
	m_score->setFont(*ASSET->getFont("H1"));
	m_score->setString( "YOUR SCORE : "+ std::to_string());
	m_score->setFillColor(sf::Color::Blue);
	m_score->setPosition(sf::Vector2f(screenWidth / 2 - 25, screenHeight / 2 - screenHeight/8));
	m_score->setScale(1.5f, 1.5f);*/
}

void PSDeath::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= m_timeRemain) {
		GSMC->ChangeState(StateTypes::STATE_END);
		ASSET->getMusic("sound")->stop();
	}
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
	window->draw(*m_text);
	//window->draw(*m_score);
}

void PSDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
