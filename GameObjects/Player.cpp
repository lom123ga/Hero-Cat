#include "Player.h"
#include "PSRun.h"
#include "PSJump.h"
#include "PSDeath.h"
#include "PSAttack.h"
#include "PSIdle.h"
#include "PSFall.h"
#include "PSJump2.h"
#include "PSFall2.h"
#include "PSHurt.h"
#include "Hitbox.h"

float IPState::scaa = 1.f;
float IPState::scab = 1.f;

Player::Player()
{
	m_nextState = IPState::SNULL;
	m_idleState = new PSIdle(this);
	m_runState = new PSRun(this);
	m_jumpState = new PSJump(this);
	m_jump2State = new PSJump2(this);
	m_fallState = new PSFall(this);
	m_fall2State = new PSFall2(this);
	m_deathState = new PSDeath(this);
	m_attackState = new PSAttack(this);
	m_hurtState = new PSHurt(this);

	m_HP = 4;

	m_currentState = m_idleState;

}

Player::~Player()
{
	if (m_runState != nullptr) {
		delete m_runState;
	}
	if (m_jumpState != nullptr) {
		delete m_jumpState;
	}
	if (m_jump2State != nullptr) {
		delete m_jump2State;
	}
	if (m_fallState != nullptr) {
		delete m_fallState;
	}
	if (m_deathState != nullptr) {
		delete m_deathState;
	}
	if (m_attackState != nullptr) {
		delete m_attackState;
	}
	if (m_idleState != nullptr) {
		delete m_idleState;
	}
	if (m_fallState != nullptr) {
		delete m_fallState;
	}
	if (m_fall2State != nullptr) {
		delete m_fallState;
	}
	if (m_hurtState != nullptr) {
		delete m_hurtState;
	}
	m_currentState = nullptr;
}

void Player::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}

void Player::Init()
{
	m_runState->Init();
	m_jumpState->Init();
	m_jump2State->Init();
	m_idleState->Init();
	m_fallState->Init();
	m_fall2State->Init();
	m_deathState->Init();
	m_attackState->Init();
	m_hurtState->Init();
	
	m_HitBox = new HitBox(sf::Vector2i(14, 34));
	m_HitBox->setPosition(sf::Vector2f(16, START));
	m_HitBox->Init(sf::Vector2f(100, 300));
	m_HitBox->SetTag(PLAYER);
	m_HitBox->setAlive(true);
	m_HitBox->setCanFall(true);
}

void Player::Update(float deltaTime)
{
	performStateChange();
	m_currentState->Update(deltaTime);
}

void Player::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	//window->draw(*m_HitBox);
}

HitBox* Player::getHitBox()
{
	return m_HitBox;
}

void Player::performStateChange()
{
	if (m_nextState != IPState::SNULL) {
		switch (m_nextState)
		{
		case IPState::STATE_RUN:
			m_currentState = m_runState;
			break;
		case IPState::STATE_JUMP:
			m_currentState = m_jumpState;
			break;
		case IPState::STATE_JUMP2:
			m_currentState = m_jump2State;
			break;
		case IPState::STATE_FALL:
			m_currentState = m_fallState;
			break;
		case IPState::STATE_FALL2:
			m_currentState = m_fall2State;
			break;
		case IPState::STATE_ATTACK:
			m_currentState = m_attackState;
			break;
		case IPState::STATE_DEATH:
			m_currentState = m_deathState;
			break;
		case IPState::STATE_IDLE:
			m_currentState = m_idleState;
			break;
		case IPState::STATE_HURT:
			m_currentState = m_hurtState;
			break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
		m_currentState->Reset();
	}
}
