#pragma once
#include "GameStateBase.h"
class GSInfo : public GameStateBase {
public:
	GSInfo();
	virtual ~GSInfo();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	list<GameButton*> m_listButton;
	sf::Text m_title;
	sf::Sprite m_background;
	std::list<sf::Text*> m_infor;
};