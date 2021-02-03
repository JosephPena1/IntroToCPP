#include <iostream>
#include <fstream>
#include "Game.h"

void Game::run() //Make a variable to choose a character to load from
{
	start();

	while (!getGameOver())
	{
		update();
		draw();
	}

	end();
}

//Draws name
void Game::drawName(char playerName[])
{
	std::cout << "Alexa's health: " << m_player1->getHealth() << std::endl;
	std::cout << "Alexa's defense: " << m_player1->getDefense() << std::endl;
	std::cout << std::endl;
	std::cout << "Despacito's health: " << m_player2->getHealth() << std::endl;
	std::cout << "Despacito's defense: " << m_player2->getDefense() << std::endl;
	std::cout << std::endl;
	std::cout << playerName << "'s turn." << std::endl;
	std::cout << "[1] Attack" << std::endl;
	std::cout << "[2] Defend" << std::endl;
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

	//if startChoice is 1, start new game.
	//if startChoice is 2, load game.
	switch (startChoice)
	{
	case 1:
		system("cls");
		m_player1 = new Character(47, 33, 26);
		m_player2 = new Character(25, 5, 1);

		m_player1->saveBinCharacter();
		break;

	case 2:
		system("cls");
		m_player1 = new Character();
		
		Character::loadBinCharacter(m_player1);
		//std::cout << m_player1->getDamage();
		m_player2 = new Character();
		break;
	}
}

void Game::update()
{
	char player1Name[] = "Potion Sellah";
	char player2Name[] = "Knight";
	int player1Choice = 0;
	int player2Choice = 0;

	while (!m_player1->checkHealth() && !m_player2->checkHealth())
	{
		//player 1's turn.
		drawName(player1Name);

		while (player1Choice == 0)
		{
			std::cin >> player1Choice;
			switch (player1Choice)
			{
			case 1:
				m_player1->attack(m_player2);
				std::cout << "Player2 took " << m_player1->getDamage() << std::endl;
				player1Choice = 1;
				break;

			case 2:
				if (m_player1->incDefense())
					std::cout << "Player1 uses harden, +2 defense" << std::endl;

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
			std::cout << "Player2 is dead." << std::endl;
			system("pause");
			system("cls");
			return;
		}
		system("pause");
		system("cls");

		//player 2's turn.
		drawName(player2Name);

		while (player2Choice == 0)
		{
			std::cin >> player2Choice;
			switch (player2Choice)
			{
			case 1:
				m_player2->attack(m_player1);
				std::cout << " Player1 took " << m_player2->getDamage() << std::endl;
				player2Choice = 1;
				break;

			case 2:
				if (m_player2->incDefense())
					std::cout << "Player2 uses harden, +2 defense" << std::endl;

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
			std::cout << "Player1 is dead." << std::endl;
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
		std::cout << "Player2 Wins!" << std::endl;
	else
		std::cout << "Player1 Wins!" << std::endl;

	system("pause");
	setGameOver(true);
}

void Game::end()
{
	delete m_player1;
	delete m_player2;
}