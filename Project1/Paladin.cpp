#include "Paladin.h"

#include <iostream>

Paladin::Paladin()
{
    className = "Паладин";
    intellect = 25;
    strength = 19;
    health = 25;
    damage = 25;
    armor = 20;
}

void Paladin::Create()
{
    std::cout << "Вы создали паладина!\n";
    std::cout << "Задайте имя игрока: ";
    std::cin >> name;

    if (weapons.empty())
    {
        Weapon weapon;
        weapon.damage = 5;
        weapon.name = "Меч";
        weapons.push_back(weapon);
    }

    if (spells.empty())
    {
        Spell spell;
        spell.damage = 2;
        spell.name = "Вспышка";
        spells.push_back(spell);
    }

    GetInfo();
    GetWeapon();
    LearnSpell();
}

void Paladin::GetInfo() const
{
    NPC::GetInfo();
    std::cout << "Сила: " << strength << '\n';
    std::cout << "Интеллект: " << intellect << '\n';
}

void Paladin::Relaculate()
{
    NPC::Relaculate();
    damage += static_cast<unsigned int>(strength / 10);
    health += static_cast<unsigned int>(strength / 5);
    damage += static_cast<unsigned int>(intellect / 10);
}

Paladin::~Paladin()
{
    std::cout << name << " отправляется к праотцам\n";
}
