#include <iostream>
#include <fstream>
#include "Character.h"

int main()
{
	Character player = Character();
	player.health = 243;
	player.damage = 2;

	/*Example of saving to a text file.*/
	//Create an instance of a file stream.
	std::fstream file;

	//Search for the file with the name given in the first
	//argument. If no file with this name exists, one with
	//the name is created. Then "std::ios::out" is used to
	//say that we want to output data to the text file.
	file.open("save.txt", std::ios::out | std::ios::_Nocreate);

	//Checks if the file isn't open. If so, return from main.
	if (!file.is_open())
	{
		return 1;
	}

	//write player stats to the text file
	file << player.health << std::endl;
	file << player.damage;

	//Closes the file when finished writing to it.
	file.close();

	/*Example of loading from a text file.*/
	Character player2 = Character();

	//Search for a file that has the name given in the first
	//argument. The "std::ios::in" argument is used to say
	//that we want to get input from the file.
	file.open("save.txt", std::ios::in);

	//Checks if the file isn't open. If so, return from main.
	if (!file.is_open())
	{
		return 1;
	}

	//Reads the player stats from the text file.
	file >> player2.health;
	file >> player2.damage;

	//Closes the file when finished reading from it.
	file.close();

	return 0;
}