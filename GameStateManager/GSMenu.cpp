#include "GSMenu.h"

GSMenu::GSMenu()
{
	//GameConnector();

	//CoinsManager();
	//ExpsManager();
	//TiledMap();

	//WavesManager();
	//MobsManager();
	//BulletsManager();

	//UI();
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	GameButton* button;

	//Enter Play Button
	button = new GameButton();
	button->Init("play");
	button->setOnClick([]() {GSMC->PushState(StateTypes::STATE_PLAY); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - 3 * screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Setting Button
	button = new GameButton();
	button->Init("setting");
	button->setOnClick([]() {GSMC->PushState(StateTypes::STATE_SETTING); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Info Button
	button = new GameButton();
	button->Init("info");
	button->setOnClick([]() {GSMC->PushState(StateTypes::STATE_INFO); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Exit Button
	button = new GameButton();
	button->Init("exit");
	button->setOnClick([]() {WConnect->getWindow()->close(); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + 3 * screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Background
	sf::Texture* texture = ASSET->getTexture("./background/meo");
	m_background.setTexture(*texture);

	m_background.setPosition(screenWidth / 2, screenHeight / 2);
	m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_background.setScale(1.f * screenWidth / m_background.getTexture()->getSize().x, 1.f * screenHeight / m_background.getTexture()->getSize().y);

	//Title
	m_title.setString(titleGame);
	m_title.setFont(*ASSET->getFont("H1"));
	m_title.setPosition(screenWidth / 2, screenHeight / 4);
	m_title.setFillColor(sf::Color( 120, 60, 30));
	m_title.setCharacterSize(150.0f);
	m_title.setOrigin(m_title.getLocalBounds().left + m_title.getLocalBounds().width / 2.0f, m_title.getLocalBounds().top + m_title.getLocalBounds().height / 3.0f);

}

void GSMenu::Update(float deltaTime)
{
	WConnect->getWindow()->setMouseCursorVisible(true);
	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->setView(window->getDefaultView());
	window->draw(m_background);
	window->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(window);
	}
}
