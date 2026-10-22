#pragma once

#include "Enums.h"
#include <string>

class Weapon {
private:
    std::string name;
    int baseDamage;
    WeaponQuality quality;

public:

    Weapon(std::string n, int damage, WeaponQuality q);

    WeaponQuality getQuality() const { return quality; }
    void printDescription() const;
};