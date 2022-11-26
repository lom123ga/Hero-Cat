#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"

class Block {
public:
	Block();
	~Block();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow* window);
	void Reset();
	HitBox* getHitBox() { return m_HitBox; }
protected:
	HitBox* m_HitBox;
	Animation* m_Block;
};