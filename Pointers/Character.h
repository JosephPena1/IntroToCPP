#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage);
	void attack(Character other);
	float takeDamage(float damageAmount);
	float getHealth() { return m_health; }
	float getDamage() { return m_damage; }

private:
	float m_health;
	float m_damage;
};

