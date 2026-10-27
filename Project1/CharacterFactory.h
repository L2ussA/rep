#pragma once

#include "NPC.h"

#include <memory>

class CharacterFactory
{
public:
    static std::unique_ptr<NPC> CreateCharacter(short choice);
};
