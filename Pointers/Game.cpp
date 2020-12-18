#include <iostream>
#include <fstream>
#include "Game.h"

void Game::run()
{
	start();

	while (!getGameOver())
	{
		update();
		draw();
	}

	end();
}

void Game::drawName(char playerName[], Character* target)
{
	std::cout << m_player1Name << "'s health: " << m_player1->getHealth() << std::endl;
	std::cout << m_player1Name << "'s defense: " << m_player1->getDefense() << std::endl;
	std::cout << std::endl;
	std::cout << m_player2Name << "'s health: " << m_player2->getHealth() << std::endl;
	std::cout << m_player2Name << "'s defense: " << m_player2->getDefense() << std::endl;
	std::cout << std::endl;
	std::cout << playerName << "'s turn." << std::endl;
	std::cout << "[1] Attack" << std::endl;
	std::cout << std::endl;
	std::cout << "> ";
}

void Game::start()
{
	int startChoice = 0;
	std::cout << "Would you like to start a new game?" << std::endl;
	std::cout << "[1] Yes" << std::endl;
	std::cout << "[2] No" << std::endl;
	std::cout << std::endl;
	std::cout << "> ";
	std::cin >> startChoice;

	switch (startChoice)
	{
	case 1:
		std::cout << "Enter Player 1's name" << std::endl;
		std::cout << "> ";
		std::cin >> m_player1Name;
		m_player1->nameCharacter(m_player1Name);
		system("cls");

		std::cout << "Enter Player 2's name" << std::endl;
		std::cout << "> ";
		std::cin >> m_player2Name;
		m_player2->nameCharacter(m_player2Name);
		system("cls");

		m_player1 = new Character(50, 10, 2);
		m_player2 = new Character(25, 5, 1);

		m_player1->save();
		m_player2->save();
		break;

	case 2:
		m_player1->load();
		m_player2->load();
		break;
	}
}

void Game::update()
{
	int player1Choice = 0;
	int player2Choice = 0;

	while (!m_player1->checkHealth() && !m_player2->checkHealth())
	{
		//player 1's turn.
		drawName(m_player1Name, m_player2);
		while (player1Choice == 0)
		{
			std::cin >> player1Choice;
			switch (player1Choice)
			{
			case 1:
				m_player1->attack(m_player2);
				std::cout << m_player2Name << " took " << m_player1->getDamage() << std::endl;
				player1Choice = 1;
				break;

			case 2:
				if (m_player1->incDefense())
					std::cout << m_player1Name << " uses harden, +2 defense" << std::endl;

				player1Choice = 2;
				break;

			default:
				player1Choice = 0;
				break;
			}
		}
		//checks if player 2 is alive
		if (m_player2->checkHealth())
		{
			std::cout << m_player2Name << " is dead." << std::endl;
			system("pause");
			system("cls");
			return;
		}
		system("pause");
		system("cls");

		//player 2's turn.
		drawName(m_player2Name, m_player1);
		while (player2Choice == 0)
		{
			std::cin >> player2Choice;
			switch (player2Choice)
			{
			case 1:
				m_player2->attack(m_player1);
				std::cout << m_player1Name << " took " << m_player2->getDamage() << std::endl;
				player2Choice = 1;
				break;

			case 2:
				if (m_player2->incDefense())
					std::cout << m_player2Name << " uses harden, +2 defense" << std::endl;

				player2Choice = 2;
				break;

			default:
				player2Choice = 0;
				break;
			}
		}
		
		//checks if player 1 is alive
		if (m_player1->checkHealth())
		{
			std::cout << m_player1Name << " is dead." << std::endl;
			system("pause");
			system("cls");
			return;
		}
		player1Choice = 0;
		player2Choice = 0;
		system("pause");
		system("cls");
		
	} //restart loop if neither player's hp is 0;
}

void Game::draw()
{
	if (m_player1->getHealth() <= 0)
		std::cout << m_player2Name << " Wins!" << std::endl;
	else
		std::cout << m_player1Name << " Wins!" << std::endl;

	system("pause");
	setGameOver(true);
}

void Game::end()
{
	delete m_player1;
	delete m_player2;
}