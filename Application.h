#pragma once
#include <SFML/Graphics.hpp>
#include "GameConfig.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameManager/ResourceManager.h"

class Application {
private:
	// variable :

	sf::RenderWindow* m_window;

	// function :

	void Init();
	void Update(float deltaTime);
	void Render();
public:

	// function :
	void Run();
	~Application();
};