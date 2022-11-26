#pragma once
#include "IPState.h"
#include "IPlayer.h"
#include "../GameStateManager/GameStateMachine.h"
#include "Player.h"

class PSDeath :public IPState {
public:
	PSDeath(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();
	
private:
	IPlayer* m_Player;
	Animation* m_Animation;
	float m_currentTime;
	float m_timeRemain;
	sf::Text* m_text;
	sf::Text* m_score;
};