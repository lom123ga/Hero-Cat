#include "Coin.h"

Coin::Coin()
{
    m_stop = true;
}

Coin::~Coin()
{
    if (m_Coin != nullptr) delete m_Coin;
}

void Coin::Init()
{
    m_HitBox = new HitBox(sf::Vector2i(22, 32));
    m_HitBox->Init(sf::Vector2f(0, 0));
    m_Coin = new Animation(*ASSET->getTexture("fish"), sf::Vector2i(1, 1), 0.1f);
    m_stop = false;
}

void Coin::Update(float deltaTime)
{

    if (m_HitBox->isAlive()) {
        m_Coin->Update(deltaTime);
        m_Coin->setPosition(m_HitBox->getPosition());
    }
}

void Coin::Render(sf::RenderWindow* window)
{
    if (m_HitBox->isAlive()) {
        window->draw(*m_Coin);
        //window->draw(*m_HitBox);
    }
}

void Coin::Reset(sf::Vector2f pos)
{
    m_HitBox->setPosition(pos);
    m_Coin->setPosition(m_HitBox->getPosition());
    m_stop = true;
}
