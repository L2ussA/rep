#pragma once

#include "NPC.h"
#include "Weapon.h"

#include <string>
#include <vector>

class Warrior : virtual public NPC
{
protected:
    short strength{ 21 };
    std::vector<Weapon> weapons;

public:
    Warrior();
    Warrior(std::string name, unsigned int lvl);

    void Create() override;
    void GetInfo() const override;
    void GetWeapon() const;
    void Relaculate() override;

    ~Warrior() override;
};
