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

	file.open("save.txt", std::ios::out);

	if (!file.is_open())
		return 1;

	file << "Placeholder" << std::endl;
	file << m_health << std::endl;
	file << m_damage << std::endl;
	file << m_defense;

	file.close();
}

bool Character::load()
{
	std::fstream file;

	file.open("save.txt", std::ios::in);

	if (!file.is_open())
	{
		return 1;
	}

	file >> m_health;
	file >> m_damage;
	file >> m_defense;

	file.close();
}

bool Character::saveBinCharacter()
{
	std::fstream file;

	return false;
}

bool Character::loadBinCharacter()
{
	std::fstream file;

	return false;
}
