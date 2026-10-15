#pragma once
#include <iostream> 
#include<vector>
using namespace std;

class Player
{
private:
	unique_ptr<NPC> currentCharacter{ nullptr };
	unique_ptr<NPC> informaton{ nullptr };
public:
	void Create(unique_ptr<NPC> character);
	NPC* GetCharacter();

	void GetInfo(unique_ptr<NPC> info);
	NPC* GetIN();
};