#pragma once
#include <SFML/Graphics.hpp>
#include "../GameManager/ResourceManager.h"
#include "GameStateMachine.h"

#include "../GameObjects/Player.h"

class GameStateBase {
public:
	GameStateBase();
	virtual ~GameStateBase();
	static GameStateBase* CreateState(StateTypes st);

	virtual void Exit() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

};