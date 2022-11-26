#pragma once
#include "IPlayer.h"

class PSFall2 :public IPState {
public:
	PSFall2(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();


private:
	IPlayer* m_Player;
	Animation* m_Animation;

	float m_currentTime;

};