#pragma once

#include "NPC.h"
#include "Spell.h"

#include <vector>

class Wizard : virtual public NPC
{
protected:
    short intellect{ 29 };
    std::vector<Spell> spells;

public:
    Wizard();

    void Create() override;
    void GetInfo() const override;
    void LearnSpell() const;
    void Relaculate() override;

    ~Wizard() override;
};
