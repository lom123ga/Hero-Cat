#pragma once
#include "IPlayer.h"
#include "SFML/Graphics.hpp"

class Player : public IPlayer
{
public:
	Player();
	~Player();
	void changeNextState(IPState::STATE nextState);

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	int getHP() { return m_HP; }
	void setHP(int HP) { m_HP = HP; }
	float getSAB() { return IPState::scaa; }
	void setScore(int score) { m_score = score; }
	int getScore() { return m_score; }
	HitBox* getHitBox();

private:
	void performStateChange();
	HitBox* m_HitBox;

	IPState::STATE m_nextState;

	int m_HP;
	int m_score;

	IPState* m_currentState;
	IPState* m_runState;
	IPState* m_jumpState;
	IPState* m_jump2State;
	IPState* m_fallState;
	IPState* m_fall2State;
	IPState* m_deathState;
	IPState* m_attackState;
	IPState* m_idleState;
	IPState* m_hurtState;
	
};