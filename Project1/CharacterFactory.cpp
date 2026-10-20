#include "CharacterFactory.h"

#include "Paladin.h"
#include "Warrior.h"
#include "Wizard.h"

std::unique_ptr<NPC> CharacterFactory::CreateCharacter(short choice)
{
    switch (choice)
    {
    case 1:
        return std::make_unique<Warrior>();
    case 2:
        return std::make_unique<Wizard>();
    case 3:
        return std::make_unique<Paladin>();
    default:
        return nullptr;
    }
}
