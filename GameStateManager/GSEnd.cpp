#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	GameButton* button;
	//menu Button
	button = new GameButton();
	button->Init("menu");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 2);
	button->setOnClick([]() {
		GSMC->PopState();
		GSMC->PopState();
		//ScoreManager::GetInstance()->UpdateHighScore();
		//ScoreManager::GetInstance()->writeFile();
		});
	m_listButton.push_back(button);

	//replay Button
	button = new GameButton();
	button->Init("restart");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100,100));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 2);
	button->setOnClick([]() {
		GSMC->PopState();
		GSMC->ChangeState(StateTypes::STATE_PLAY);
		//ScoreManager::GetInstance()->UpdateHighScore();
		//ScoreManager::GetInstance()->writeFile();
		});
	m_listButton.push_back(button);



	// background
	sf::Texture* texture = ASSET->getTexture("background/City");
	m_background.setTexture(*texture);
	m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_background.setPosition(screenWidth / 2, screenHeight / 2);
	m_background.setScale(1.f * screenWidth / m_background.getTexture()->getSize().x, 1.f * screenHeight / m_background.getTexture()->getSize().y);
}

void GSEnd::Update(float deltaTime)
{
	WConnect->getWindow()->setMouseCursorVisible(true);
	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->setView(window->getDefaultView());
	window->draw(m_background);
	//window->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(window);
	}
}
