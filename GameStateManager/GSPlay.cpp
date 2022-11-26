#include "GSPlay.h"

GSPlay::GSPlay()
{

	m_Player = new Player;
	
	m_CoinManager = new CoinManager();
	m_view = new sf::View;
	m_MapManager = new MapManager;
	m_currentScore = 0;
	m_currentTime = 0.f;

	m_Rock = new Rock;

}

GSPlay::~GSPlay()
{
	if (m_Player != nullptr) delete m_Player;
	if (m_MapManager != nullptr) delete m_MapManager;
	if (m_CoinManager != nullptr) delete m_CoinManager;
	if (m_Rock != nullptr) delete m_Rock;
	
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
	WConnect->getWindow()->setMouseCursorVisible(false);
}

void GSPlay::Init()
{
	WConnect->getWindow()->setMouseCursorVisible(true);
	printf("Play game");
	m_background.Init();
	m_Rock->Init();
	m_CollisionManager.addObj(m_Rock->getHitbox());
	m_MapManager->Init(m_CollisionManager);
	m_CoinManager->Init(m_CollisionManager);

	m_Player->Init();
	GUI->Init();
	m_view->setSize(screenWidth, screenHeight);
	m_CollisionManager.addObj(m_Player->getHitBox());

	m_Player->getHitBox()->setHP(4);

	ASSET->playMusic("sound");
	ASSET->getMusic("sound")->setLoop(true);
	ASSET->getMusic("sound")->setVolume(20);

	GameButton* button;

	//Enter Play Button
	button = new GameButton();
	button->Init("pause");
	button->setOnClick([]() {GSMC->PushState(StateTypes::STATE_PAUSE); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 +  screenWidth / 3 + 75, screenHeight / 8);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

}

void GSPlay::Update(float deltaTime)
{

	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}

	m_MapManager->Update(deltaTime);
	m_CoinManager->Update(deltaTime);
	GUI->setHP(m_Player->getHP());

	if (m_Player->getHitBox()->isAlive()) {
		m_currentScore = m_CoinManager->checkCoin();
		GUI->setCoin(m_currentScore);
	}

	if (m_Player->getHitBox()->isAlive()) m_background.Update(deltaTime);
	m_Player->Update(deltaTime);
	if (m_Player->getHitBox()->isAlive()) {
		if (m_Player->getHitBox()->getAttack()) {
		
			if (!m_Rock->getHitbox()->isAlive()) {
				m_Rock->setAAC(m_Player->getSAB());
				
				m_Rock->setStartPoint(sf::Vector2f(m_Player->getHitBox()->getPosition().x+16, m_Player->getHitBox()->getPosition().y-5));
				m_Rock->getHitbox()->setAlive(true);
			}
			m_Player->getHitBox()->setAttack(false);
		}

		m_Rock->Update(deltaTime);
		m_CollisionManager.Update();
		GUI->Update(deltaTime);
	}

	m_Player->setScore(GUI->getCoin());

	float id_x = m_Player->getHitBox()->getPosition().x;
	if (id_x <= screenWidth / 2.0) id_x = screenWidth / 2.0;
	m_view->setCenter(id_x,screenHeight/2.0);
}

void GSPlay::Render(sf::RenderWindow* window)
{
	window->setView(*m_view);
	m_background.Render(window);
	m_MapManager->Render(window);
	if (m_Rock->getHitbox()->isAlive()) m_Rock->Render(window);
	m_Player->Render(window);
	m_CoinManager->Render(window);
	window->setView(window->getDefaultView());
	GUI->Render(window);
	for (auto it : m_listButton) {
		it->Render(window);
	}
	window->setView(*m_view);
}
