#pragma once
#include "Character.h"

class Game
{
public:
	void run();

	bool getGameOver() { return m_gameOver; }
	void setGameOver(bool value) { m_gameOver = value; }
	void drawName(char playerName[],  Character* target);
	char* getName1() { return m_player1Name; }
	char* getName2() { return m_player2Name; }
	bool saveBin();
	bool loadBin();

public:

private:
	void start();
	void update();
	void draw();
	void end();

private:
	bool m_gameOver;
	char m_player1Name[10];
	char m_player2Name[10];
	Character* m_player1;
	Character* m_player2;
};