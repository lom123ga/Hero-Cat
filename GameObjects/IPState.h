#pragma once
#include "../GameManager/ResourceManager.h"


class IPState {
public:
	enum STATE
	{
		STATE_RUN,
		STATE_JUMP,
		STATE_JUMP2,
		STATE_IDLE,
		STATE_DEATH,
		STATE_ATTACK,
		STATE_FALL,
		STATE_FALL2,
		STATE_HURT,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
	static float scaa ;
	static float scab ;
};