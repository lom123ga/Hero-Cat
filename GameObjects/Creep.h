#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"

class Creep {
public:
	Creep();
	~Creep();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow* window);

	HitBox* getHitBox() { return m_HitBox; }
	void setStartPoint(sf::Vector2f point) { 
		m_HitBox->setPosition(point);
		m_currentAni->setPosition(point);
	}

	void Reset();
	bool isStop() { return m_stop; }
	void setTime(float time) { m_time = time; }
protected:
	sf::Vector2f m_startPoint;
	HitBox* m_HitBox;
	Animation* m_currentAni;
	Animation* m_deathAni;
	Animation* m_runAni;
	
	float m_time;
	float m_currentTime;
	bool m_stop;
	bool m_soundDeadisPlay;
	sf::Vector2f sca;
};