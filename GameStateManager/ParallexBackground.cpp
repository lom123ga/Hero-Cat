#include "ParallexBackground.h"

void ParallexBackground::Init()
{
	Animation* ani1;
	Animation* ani2;
	for (int i = 0; i < 5; i++) {
		ani1 = new Animation(*ASSET->getTexture("pbg/Background_1"), sf::Vector2i(1, 1), 0.1f);
		ani1->setPosition(sf::Vector2f(1167 * i + 1167 / 2.0, 640 / 2));
		m_Background1.push_back(ani1);
		ani2 = new Animation(*ASSET->getTexture("pbg/Background_2"), sf::Vector2i(1, 1), 0.1f);
		ani2->setPosition(sf::Vector2f(1167 * i + 1167 / 2.0, 640 / 2));
		m_Background1.push_back(ani2);
	}

}

void ParallexBackground::Update(float deltaTime)
{
	for (auto layer : m_Background2) {
		layer->Update(deltaTime);
	}
	for (auto layer : m_Background1) {
		layer->Update(deltaTime);
	}
}

void ParallexBackground::Render(sf::RenderWindow* window)
{
	for (auto layer : m_Background2) {
		window->draw(*layer);
	}
	for (auto layer : m_Background1) {
		window->draw(*layer);
	}
}
