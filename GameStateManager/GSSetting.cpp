#include "GSSetting.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void GSSetting::Init()
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

	//turn on music
	button = new GameButton();
	button->Init("msicon");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {ASSET->setAllowSound(true); });
	m_listButton.push_back(button);

	//turn off music
	button = new GameButton();
	button->Init("msicof");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {ASSET->setAllowSound(false); });
	m_listButton.push_back(button);

	//Background
	sf::Texture* texture = ASSET->getTexture("background/bg_setting");
	m_background.setTexture(*texture);
	m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_background.setPosition(screenWidth / 2, screenHeight  / 2);
	m_background.setScale(1.f * screenWidth / m_background.getTexture()->getSize().x, 1.f * screenHeight / m_background.getTexture()->getSize().y);

	//Title
	m_title.setString("SETTING");
	m_title.setFont(*ASSET->getFont("game_font"));
	m_title.setPosition(screenWidth / 2, screenHeight / 10);
	m_title.setFillColor(sf::Color(156, 227, 186));
	m_title.setCharacterSize(150.0f);
	m_title.setOrigin(m_title.getLocalBounds().left + m_title.getLocalBounds().width / 2.0f, m_title.getLocalBounds().top + m_title.getLocalBounds().height / 2.0f);
}

void GSSetting::Update(float deltaTime)
{
	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}
}

void GSSetting::Render(sf::RenderWindow* window)
{
	window->draw(m_background);
	window->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(window);
	}
}
