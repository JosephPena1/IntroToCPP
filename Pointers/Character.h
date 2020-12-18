#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage, float defense);
	void attack(Character* other);
	float takeDamage(float damageAmount);
	void nameCharacter(char name[]);
	bool incDefense();
	bool checkHealth();
	bool save();
	bool load();
	float getHealth() { return m_health; }
	float getDamage() { return m_damage; }
	float getDefense() { return m_defense; }

private:
	char m_name[10];
	float m_health;
	float m_damage;
	float m_defense;
};