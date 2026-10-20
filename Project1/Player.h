#pragma once

#include "NPC.h"

#include <memory>

class Player
{
private:
    std::unique_ptr<NPC> currentCharacter{ nullptr };

public:
    bool Create(short choice);
    NPC* GetCharacter();
};
