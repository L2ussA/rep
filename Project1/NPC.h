#pragma once
#include <iostream> 
#include<vector>

using namespace std;

class NPC {

protected:
	string name{ "npc" };
	unsigned int damage{ 2 };
	unsigned int health{ 5 };
	short lvl = 1;
	unsigned int armor = 2;
private:
	bool isEnemy = true;
public:
	NPC();
	unsigned int GetDamage() { return damage; };
	unsigned int GetHealth() { return health; }; // getter
	void SetHealth(unsigned int health) { this->health = health; }; // setter

	void GetInfo();
	virtual void Create() {}; // one metod virtual -> whole class virtual
	void LvlUp();
	void Relaculate(); //кастомизировать для война и волшебника зависимости от инт/силы
	friend void TakeDamage(const NPC* npc, unsigned int damage);
	virtual ~NPC() = default;
};
