#include "Player.h"

#include "CharacterFactory.h"

bool Player::Create(short choice)
{
    currentCharacter = CharacterFactory::CreateCharacter(choice);

    if (currentCharacter == nullptr)
        return false;

    currentCharacter->Create();
    return true;
}

NPC* Player::GetCharacter()
{
    return currentCharacter.get();
}
