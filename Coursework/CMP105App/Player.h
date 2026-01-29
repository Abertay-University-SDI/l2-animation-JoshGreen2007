#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Player : public GameObject
{
public:

	Player();
	virtual ~Player() = default;

	void update(float dt) override;
	void handleInput(float dt) override;

private:

	enum class Direction { UP, DOWN, LEFT, RIGHT, UP_RIGHT, DOWN_RIGHT, DOWN_LEFT, UP_LEFT, NONE };
	Direction m_direction = Direction::NONE;;
	float m_speed = 300.0f;
	float m_inputBuffer = 0.f;
	bool m_gameOver = false;

	const float INPUT_BUFFER_LENGTH = 0.1f;
	const float APPROX_ONE_OVER_ROOT_TWO = 0.70710678f;	// 1 / sqrt(2)

	Animation m_walkDown;
	Animation* m_currentAnimation;

};