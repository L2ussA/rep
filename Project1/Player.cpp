#pragma once
#include <iostream> 
#include<vector>
#include "Player.h"
#include "NPC.h"
using namespace std;

Player::Player(){
	void Player::Create(unique_ptr<NPC> character)
	{
		currentCharacter = move(character);
		currentCharacter->Create();
	}
	NPC* GetCharacter()
	{
		return currentCharacter.get();
	}

	void Player::GetInfo(unique_ptr<NPC> info)
	{
		informaton = move(info);
		informaton->GetInfo();
	}
	NPC* GetIN() {
		return informaton.get();
	}
}