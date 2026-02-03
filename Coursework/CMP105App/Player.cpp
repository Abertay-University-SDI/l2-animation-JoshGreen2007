#include "Player.h"
#include "Framework/Animation.h"

Player::Player() 
{

	setOrigin({ 32.f, 32.f });

	for (int i = 0; i < 4; i++) 
	{

		// Dimensions: (x, y), and (width, height)
		m_walkDown.addFrame(sf::IntRect({ i * 64,0 }, { 64, 64 }));

	}

	m_walkDown.setLooping(true); //Loop animation forever
	m_walkDown.setFrameSpeed(1.f / 4.f); //Change frame every 0.25 seconds

	for (int i = 0; i < 4; i++)
	{

		m_walkUp.addFrame(sf::IntRect({ (4 + i) * 64 ,0 }, { 64, 64 }));

	}

	m_walkUp.setLooping(true); //Loop animation forever
	m_walkUp.setFrameSpeed(1.f / 4.f); //Change frame every 0.25 seconds

	for (int i = 0; i < 4; i++)
	{

		m_walkSideways.addFrame(sf::IntRect({ (i * 64), 128 }, { 64, 64 }));

	}

	m_walkSideways.setLooping(true); //Loop animation forever
	m_walkSideways.setFrameSpeed(1.f / 4.f); //Change frame every 0.25 seconds

	for (int i = 0; i < 4; i++)
	{

		m_walkUpSideways.addFrame(sf::IntRect({ (i * 64), 64 }, { 64, 64 }));

	}


	//Set default animation
	m_currentAnimation = &m_walkDown;

	//The following: adds dt to an internal timer, advances the frame when enough time passes,
	//then updates the current texture
	setTextureRect(m_currentAnimation->getCurrentFrame());

}

void Player::handleInput(float dt)
{

	Direction last_dir = m_direction;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
	{

		//Note that braced brackets {} aren't needed for if statements.

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
			m_direction = Direction::UP_LEFT;

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
			m_direction = Direction::DOWN_LEFT;

		else
			m_direction = Direction::LEFT;

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
			m_direction = Direction::UP_RIGHT;

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
			m_direction = Direction::DOWN_RIGHT;

		else
			m_direction = Direction::RIGHT;
	}

	else
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
		{

			m_direction = Direction::UP;
		

		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
		{

			m_direction = Direction::DOWN;

		}

	}

	if (m_direction != last_dir)
	{

		m_inputBuffer = INPUT_BUFFER_LENGTH;

		if (m_direction == Direction::UP)
		{

			m_currentAnimation = &m_walkUp;
			setScale({ 1.f, 1.f });

		}

		if (m_direction == Direction::UP_LEFT)
		{

			m_currentAnimation = &m_walkUpSideways;
			setScale({ -1.f, 1.f });

		}

		if (m_direction == Direction::UP_RIGHT)
		{

			m_currentAnimation = &m_walkUpSideways;
			setScale({ 1.f, 1.f });

		}

		if (m_direction == Direction::DOWN)
		{

			m_currentAnimation = &m_walkDown;
			setScale({ 1.f, 1.f });

		}

		if (m_direction == Direction::LEFT)
		{

			m_currentAnimation = &m_walkSideways;
			setScale({ -1.f, 1.f });

		}

		if (m_direction == Direction::RIGHT)
		{

			m_currentAnimation = &m_walkSideways;
			setScale({ 1.f, 1.f });

		}

	}

}

void Player::update(float dt) 
{

	m_currentAnimation->animate(dt);
	setTextureRect(m_currentAnimation->getCurrentFrame());

	if (m_gameOver) return;

	// Diagonal speed has quicker movement, 1/sqrt2 is a close way to keep it similar
	// To orthog speed.
	float diagonal_speed = m_speed * APPROX_ONE_OVER_ROOT_TWO * dt;
	float orthog_speed = m_speed * dt;	// orthogonal movement

	switch (m_direction)
	{
	case Direction::UP:
		move({ 0, -orthog_speed }); // Note: up is negative y
		break;

	case Direction::UP_RIGHT:
		move({ diagonal_speed, -diagonal_speed });
		break;

	case Direction::RIGHT:
		move({ orthog_speed,0 });
		break;

	case Direction::DOWN_RIGHT:
		move({ diagonal_speed, diagonal_speed });
		break;

	case Direction::DOWN:
		move({ 0, orthog_speed }); // Note: down is positive y
		break;

	case Direction::DOWN_LEFT:
		move({ -diagonal_speed, diagonal_speed });
		break;

	case Direction::LEFT:
		move({ -orthog_speed,0 });
		break;

	case Direction::UP_LEFT:
		move({ -diagonal_speed, -diagonal_speed });
		break;

	}

}
