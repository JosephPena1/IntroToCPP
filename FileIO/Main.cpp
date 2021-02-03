#include <iostream>
#include <fstream>
#include "Character.h"

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
	//Create a character to store the loaded data.
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
	system("pause");
}