#include <iostream>
#include <fstream>
#include "Character.h"

//Regular Saving/Loading

//int main()
//{
//	Character player = Character();
//	player.health = 243;
//	player.damage = 2;
//
//	/*Example of saving to a text file.*/
//	//Create an instance of a file stream.
//	std::fstream file;
//
//	//Search for the file with the name given in the first
//	//argument. If no file with this name exists, one with
//	//the name is created. Then "std::ios::out" is used to
//	//say that we want to output data to the text file.
//	file.open("save.txt", std::ios::out | std::ios::_Nocreate);
//
//	//Checks if the file isn't open. If so, return from main.
//	if (!file.is_open())
//	{
//		return 1;
//	}
//
//	//write player stats to the text file
//	file << player.health << std::endl;
//	file << player.damage;
//
//	//Closes the file when finished writing to it.
//	file.close();
//
//	/*Example of loading from a text file.*/
//	Character player2 = Character();
//
//	//Search for a file that has the name given in the first
//	//argument. The "std::ios::in" argument is used to say
//	//that we want to get input from the file.
//	file.open("save.txt", std::ios::in);
//
//	//Checks if the file isn't open. If so, return from main.
//	if (!file.is_open())
//	{
//		return 1;
//	}
//
//	//Reads the player stats from the text file.
//	file >> player2.health;
//	file >> player2.damage;
//
//	//Closes the file when finished reading from it.
//	file.close();
//
//	return 0;
//}

//Binary Saving/Loading
bool binaryFileWrite()
{
	///Writing File
	//Initialize characters
	Character player = Character();
	player.health = 100;
	player.damage = 10;
	Character player2 = Character();
	player2.health = 150;
	player2.damage = 20;
	Character player3 = Character();
	player3.health = 200;
	player3.damage = 30;

	//Create an instance of a file stream.
	std::fstream file;

	//Open the file we want to. The first argument is the file path
	//The second is what we will be doing with the file(reading or writing)
	//followed by any extra parameters. In this case, std::ios::binary
	//to make the file created a binary file.
	file.open("save.dat", std::ios::out | std::ios::binary);

	//checks if the file is open before using it.
	if (!file.is_open())
		return false;

	//write all the characters to file.
	file.write((char*)&player, sizeof(Character));
	file.write((char*)&player2, sizeof(Character));
	file.write((char*)&player3, sizeof(Character));

	//close the file once writing is done.
	file.close();

	///Reading file
	//Create a character to styore the loaded data.
	Character player4 = Character();

	//Open the file to load from.
	file.open("save.dat", std::ios::in | std::ios::binary);

	//checks if the file is open.
	if (!file.is_open())
		return false;

	//Position the marker to two characters away from the beginning.
	file.seekg(sizeof(Character) * 2, std::ios::beg);

	//Set the character to be the value read from the file.
	file.read((char*)&player4, sizeof(Character));

	//Print the results.
	std::cout << player4.health << std::endl;
	std::cout << player4.damage << std::endl;

	//Close the file.
	file.close();
	return true;
}

//Binary saving and loading
int main()
{
	binaryFileWrite();
}