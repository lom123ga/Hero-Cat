#pragma once
#include "../GameManager/ResourceManager.h"
#include "Hitbox.h"

class Rock {
public:
	Rock();
	~Rock();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();
	void setStartPoint(sf::Vector2f point);
	void setAAC(int a) {
		aac = a;
	}
	HitBox* getHitbox() { return m_Hitbox; }

private:
	float m_currentTime;
	Animation* m_Animation;
	HitBox* m_Hitbox;
	int aac;
};