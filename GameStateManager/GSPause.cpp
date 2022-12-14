#include "GSPause.h"

GSPause::GSPause()
{
}

GSPause::~GSPause()
{
}

void GSPause::Exit()
{
}

void GSPause::Pause()
{
}

void GSPause::Resume()
{
}

void GSPause::Init()
{

	m_waitPause = 0.2f;
	m_currentPauseTime = 0.f;
	m_canPause = false;
	WConnect->getWindow()->setMouseCursorVisible(true);
	GameButton* button;

	//Continue Play
	button = new GameButton();
	button->Init("play");
	button->setOnClick([]() {GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_PLAY); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - 3 * screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Setting Button
	button = new GameButton();
	button->Init("setting");
	button->setOnClick([]() {GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_SETTING); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Info Button
	button = new GameButton();
	button->Init("info");
	button->setOnClick([]() {GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_INFO); });
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
	sf::Texture* texture = ASSET->getTexture("background/bg_setting");
	//texture->setSmooth(true);
	m_background.setTexture(*texture);

	m_background.setPosition(screenWidth / 2, screenHeight / 2);
	m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_background.setScale(1.f * screenWidth / m_background.getTexture()->getSize().x, 1.f * screenHeight / m_background.getTexture()->getSize().y);

	//Title
	m_title.setString("HERO CAT");
	m_title.setFont(*ASSET->getFont("game_font"));
	m_title.setPosition(screenWidth / 2, screenHeight / 10);
	m_title.setFillColor(sf::Color(208, 208, 225));
	m_title.setCharacterSize(170.0f);
	m_title.setOrigin(m_title.getLocalBounds().left + m_title.getLocalBounds().width / 2.0f, m_title.getLocalBounds().top + m_title.getLocalBounds().height / 3.0f);
}

void GSPause::Update(float deltaTime)
{
	m_currentPauseTime += deltaTime;
	if (m_currentPauseTime >= m_waitPause) {
		m_canPause = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && m_canPause) {
		GSMC->PopState();
	}

	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}
}

void GSPause::Render(sf::RenderWindow* window)
{
	window->draw(m_background);
	window->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(window);
	}
}