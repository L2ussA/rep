#pragma once
#include <iostream> 
#include<vector>
#include "NPC.h"
#include "Spell.h"
using namespace std;

class Wizard : virtual public NPC
{
protected:
	short intellect{ 29 };
	vector<Spell> spells;
public:
	Wizard();//конструктор вызывается в момент создания экземпляра
	void Create() override;
	void GetInfo();
	void LearnSpell();

	void Relaculate();
	~Wizard();
};