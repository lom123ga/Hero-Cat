#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallexBackground.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/CollisionManager.h"
#include "../GameObjects/CreepManager.h"
#include "../GameObjects/MapManager.h"
#include "../GameObjects/CoinManager.h"
#include "../GameObjects/RockManager.h"
#include "../GameObjects/Rock.h"
#include "../GameObjects/UI.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:

	ParallexBackground m_background;
	Player* m_Player;
	CollisionManager m_CollisionManager;

	MapManager* m_MapManager;
	CoinManager* m_CoinManager;
	list<GameButton*> m_listButton;
	Rock* m_Rock;
	sf::View* m_view;
	int m_currentScore;
	float m_currentTime;

};