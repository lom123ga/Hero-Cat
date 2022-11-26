#pragma once
#include "../GameManager/ResourceManager.h"
#include "../GameObjects/Animation.h"

class ParallexBackground
{
public:
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<Animation*> m_Background1;
	std::list<Animation*> m_Background2;
};