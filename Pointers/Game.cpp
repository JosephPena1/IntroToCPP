#include "Game.h"
#include <iostream>

void Game::run()
{
	start();

	while (!getGameOver())
	{
		update();
		draw();

		system("pause");
	}

	end();
}

void Game::start()
{
	m_player1 = Character(100, 0.5f);
	m_player2 = Character(10, 5);
}

void Game::update()
{
	m_player1.attack(m_player2);
}

void Game::draw()
{
	std::cout << "Player2 health is: " << m_player2.getHealth() << std::endl;
}

void Game::end()
{

}