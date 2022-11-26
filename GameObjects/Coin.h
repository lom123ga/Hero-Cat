#pragma once
#include "../GameManager/ResourceManager.h"
#include "Hitbox.h"

class Coin {
public:
	Coin();
	~Coin();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset(sf::Vector2f pos);
	HitBox* getHitBox() { return m_HitBox; }
	bool getStop() { return m_stop; }
	void setStop(bool stop) { m_stop = stop; }
protected:
	Animation* m_Coin;
	HitBox* m_HitBox;
	bool m_stop;
};