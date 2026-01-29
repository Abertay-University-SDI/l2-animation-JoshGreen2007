#include "Player.h"
#include "Framework/Animation.h"

Player::Player() 
{

	for (int i = 0; i < 4; i++) 
	{

		m_walkDown.addFrame(sf::IntRect({ i * 64,0 }, { 64, 64 }));

	}

	m_walkDown.setLooping(true);
	m_walkDown.setFrameSpeed(1.f / 4.f);
	m_currentAnimation = &m_walkDown;
	setTextureRect(m_currentAnimation->getCurrentFrame());

}

void Player::handleInput(float dt)
{



}

void Player::update(float dt) 
{

	m_currentAnimation->animate(dt);
	setTextureRect(m_currentAnimation->getCurrentFrame());

}
