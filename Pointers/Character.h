#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage, float defense);
	void attack(Character* other);
	float takeDamage(float damageAmount);
	bool incDefense();
	bool checkHealth();
	bool save();
	bool load();
	bool saveBinCharacter();
	static bool loadBinCharacter(Character* player);
	float getHealth() { return m_health; }
	float getDamage() { return m_damage; }
	float getDefense() { return m_defense; }

private:
	float m_health;
	float m_damage;
	float m_defense;
};