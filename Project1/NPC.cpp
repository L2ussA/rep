#include <iostream>
#include "NPC.h"
using namespace std;

NPC :: NPC() {
	cout << "Dead" << endl;
	name = "npc";
	damage = 2;
	health = 5;
	lvl = 1;
	armor = 2;
}
unsigned int NPC::GetDamage() { return damage; };
unsigned int NPC::GetHealth() { return health; }; // getter
void NPC::SetHealth(unsigned int health) { this->health = health; }; // setter

void NPC::GetInfo()
{
	cout << "имя: " << name << endl;
	cout << "здоровье: " << health << endl;
	cout << "урон: " << damage << endl;
	cout << "уровень: " << lvl << endl;
	cout << "броня: " << armor << endl;
};
void NPC::Create() {} // one metod virtual -> whole class virtual
void NPC::LvlUp()
{
	cout << name << " получил новый уровень" << endl;
	lvl;
	Relaculate();
}
void NPC::Relaculate() //кастомизировать для война и волшебника зависимости от инт/силы
{
	damage += (1 + lvl * 0.1);
	health += (1 + lvl * 0.1);
	armor += (1 + lvl * 0.1);
}
