#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{

	if (!m_playerTexture.loadFromFile("gfx/sheep_sheet.png"))
	{

		std::cerr << "No Sheep image found\n";

	}

		//Load Sheep onto screen
		m_player.setTexture(&m_playerTexture, true); //Attach Texture to Player
		m_player.setPosition({ 50, 0 }); //Set Player position
		m_player.setTextureRect(sf::IntRect({ 0, 0 }, { 64, 64 })); //Set Player size
		m_player.setSize({ 64.f, 64.f }); //Place Sheep image on screen

}

// handle user input
void Level::handleInput(float dt)
{
	
	m_player.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{

	m_player.update(dt);

}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_player);
	endDraw();
}

