#include <iostream> 
#include<vector>
#include "Paladin.h"
using namespace std;

Paladin::Paladin()
{
	intellect = 25;
	strength = 19;
	health = 25;
	damage = 25;
	Create();
}
void Paladin::Create()
{
	// реализуйте это в npc (храниетет название в каком то поле)
	cout << "Вы создали Паладина\nЗадайте имя игрока\n";
	cin >> name;

	GetInfo();
	GetWeapon();
	LearnSpell();

};
void Paladin::GetInfo()
{
	Warrior::GetInfo();
	cout << "интеллект: " << intellect << endl;
};
Paladin::~Paladin()
{
	cout << "отправляется к праотцам " << endl;
}