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
	void Create(unique_ptr<NPC> character)
	{
		currentCharacter = move(character);
		currentCharacter->Create();
	}
	NPC* GetCharacter()
	{
		return currentCharacter.get();
	}

	void GetInfo(unique_ptr<NPC> info)
	{
		informaton = move(info);
		informaton->GetInfo();
	}
	NPC* GetIN() {
		return informaton.get();
	}
};