#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

//Player is a GameObject
//it has: position, move(), draw(), texture, size
class Player : public GameObject
{
public:

	Player();

	//Virtual means the function can be replaced - its done so wrong parameter types cannot be entered.
	virtual ~Player() = default;

	void update(float dt) override; //override is a replacement of a virtual function
	void handleInput(float dt) override; //This replaces GameObject::update() with GameObject::handleInput()

private:

	enum class Direction { UP, DOWN, LEFT, RIGHT, UP_RIGHT, DOWN_RIGHT, DOWN_LEFT, UP_LEFT, NONE };
	Direction m_direction = Direction::NONE;
	float m_speed = 300.0f;
	float m_inputBuffer = 0.f;
	bool m_gameOver = false;

	const float INPUT_BUFFER_LENGTH = 0.1f;
	const float APPROX_ONE_OVER_ROOT_TWO = 0.70710678f;	// 1 / sqrt(2)

	Animation m_walkDown; // Stores rectangles in sf::IntRect
	Animation m_walkUp;
	Animation* m_currentAnimation;

};