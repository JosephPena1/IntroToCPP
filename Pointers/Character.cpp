#include <iostream>
#include <fstream>
#include "Character.h"

Character::Character()
{
	m_health = 100;
	m_damage = 10;
	m_defense = 10;
}

Character::Character(float health, float damage, float defense)
{
	m_health = health;
	m_damage = damage;
	m_defense = defense;
}

void Character::attack(Character* other)
{
	other->takeDamage(getDamage());
}

float Character::takeDamage(float damageAmount)
{
	damageAmount -= m_defense;
	m_health -= damageAmount;
	return damageAmount;
}

bool Character::incDefense()
{
	if (m_defense != m_damage - 2)
	{
		m_defense += 2;
		return true;
	}
	else
	{
		std::cout << "Your defense is already maxed." << std::endl;
		return false;
	}
}

bool Character::checkHealth()
{
	if (getHealth() <= 0)
		return true;

	return false;
}

bool Character::save()
{
	std::fstream file;
	Character* player = this;

	file.open("save.txt", std::ios::out);

	if (!file.is_open())
		return false;

	file.write((char*)&player, sizeof(Character));
	/*file << m_health << std::endl;
	file << m_damage << std::endl;
	file << m_defense;*/

	file.close();
	return true;
}

bool Character::load()
{
	std::fstream file;

	file.open("save.txt", std::ios::in);

	if (!file.is_open())
	{
		return false;
	}

	file >> m_health;
	file >> m_damage;
	file >> m_defense;

	file.close();
	return true;
}

//Saves Character to binary file.
bool Character::saveBinCharacter()
{
	std::fstream file;
	Character* player = this;

	file.open("save.dat", std::ios::in | std::ios::binary);

	if (!file.is_open())
		return false;

	file.write((char*)&player, sizeof(Character));
	file.close();
	return true;
}

//Loads Character from Binary file.
bool Character::loadBinCharacter(Character* player)
{
	//creates a temporary character pointer
	Character* playerStats = player;
	std::fstream file;

	file.open("save.dat", std::ios::out | std::ios::binary);

	if (!file.is_open())
		return false;

	//Position the marker to two characters away from the beginning.
	//file.seekg(sizeof(Character) * 2, std::ios::beg);

	//Set the character to be the value read from the file.
	//file.read((char*)&playerStats, sizeof(Character));

	file.read((char*)&player, sizeof(Character));
	file >> player->m_health;
	file >> player->m_damage;
	file >> player->m_defense;

	std::cout << player->getHealth() << std::endl;
	std::cout << player->getDamage() << std::endl;
	std::cout << player->getDefense() << std::endl;
	system("pause");

	//Close the file.
	file.close();

	//sets player to playerstats
	player = playerStats;

	return true;
}