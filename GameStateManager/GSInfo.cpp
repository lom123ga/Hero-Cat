#include "GSInfo.h"

GSInfo::GSInfo()
{
}

GSInfo::~GSInfo()
{
}

void GSInfo::Exit()
{
}

void GSInfo::Pause()
{
}

void GSInfo::Resume()
{
}

void GSInfo::Init()
{
	GameButton* button;

	// Return Button
	button = new GameButton();
	button->Init("exit");
	button->setOnClick([]() {GSMC->PopState(); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth - screenWidth / 16, screenHeight / 13);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Background
	sf::Texture* texture = ASSET->getTexture("background/bg_info");
	m_background.setTexture(*texture);
	m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_background.setPosition(screenWidth / 2, screenHeight / 2);
	m_background.setScale(1.f * screenWidth / m_background.getTexture()->getSize().x, 1.f * screenHeight / m_background.getTexture()->getSize().y);

	//Title
	m_title.setString("ABOUT");
	m_title.setFont(*ASSET->getFont("game_font"));
	m_title.setPosition(screenWidth / 2, screenHeight / 10);
	m_title.setFillColor(sf::Color( 255, 135, 204));
	m_title.setCharacterSize(150.0f);
	m_title.setOrigin(m_title.getLocalBounds().left + m_title.getLocalBounds().width / 2.0f, m_title.getLocalBounds().top + m_title.getLocalBounds().height / 2.0f);

	sf::Text* text = new sf::Text();
	text->setFont(*ASSET->getFont("H1"));
	text->setFillColor(sf::Color::Black);
	text->setString("Di chuyen bang cac nut A W D S va nem da bang SPACE");
	text->setPosition(sf::Vector2f(screenWidth/6,screenHeight/4));
	//text->setScale(1.5f, 1.5f);
	m_infor.push_back(text);
	text = new sf::Text();
	text->setFont(*ASSET->getFont("H1"));
	text->setFillColor(sf::Color::Black);
	text->setString("Ban co 4 mang , neu bi thuong qua 4 lan ban se chet");
	text->setPosition(sf::Vector2f(screenWidth / 6, screenHeight / 2));
	//text->setScale(1.5f, 1.5f);
	m_infor.push_back(text);
}

void GSInfo::Update(float deltaTime)
{
	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}
}

void GSInfo::Render(sf::RenderWindow* window)
{
	window->draw(m_background);
	for (auto button : m_listButton) {
		button->Render(window);
	}
	for (auto infor : m_infor) {
		window->draw(*infor);
	}
	window->draw(m_title);
}
