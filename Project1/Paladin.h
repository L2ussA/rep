#pragma once
#include <iostream> 
#include<vector>
#include "Warrior.h"
#include "Wizard.h"
using namespace std;

class Paladin : public Warrior, public Wizard
{
public:
	Paladin();
	void Create() override;
	void GetInfo();
	~Paladin();
};