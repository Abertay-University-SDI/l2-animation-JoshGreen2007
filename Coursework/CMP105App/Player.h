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

	Animation m_walkDown;
	Animation* m_currentAnimation;

};