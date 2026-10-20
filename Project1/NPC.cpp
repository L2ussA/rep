#include "NPC.h"

#include <iostream>

NPC::NPC()
{
    name = "npc";
    damage = 2;
    health = 5;
    lvl = 1;
    armor = 2;
}

unsigned int NPC::GetDamage() const
{
    return damage;
}

unsigned int NPC::GetHealth() const
{
    return health;
}

void NPC::SetHealth(unsigned int health)
{
    this->health = health;
}

void NPC::GetInfo() const
{
    std::cout << "Имя: " << name << '\n';
    std::cout << "Класс: " << className << '\n';
    std::cout << "Здоровье: " << health << '\n';
    std::cout << "Урон: " << damage << '\n';
    std::cout << "Уровень: " << lvl << '\n';
    std::cout << "Броня: " << armor << '\n';
}

void NPC::LvlUp()
{
    std::cout << name << " получил новый уровень\n";
    ++lvl;
    Relaculate();
}

void NPC::Relaculate()
{
    damage += static_cast<unsigned int>(1 + lvl * 0.1);
    health += static_cast<unsigned int>(1 + lvl * 0.1);
    armor += static_cast<unsigned int>(1 + lvl * 0.1);
}

void TakeDamage(NPC* npc, unsigned int damage)
{
    if (npc == nullptr)
        return;

    if (damage >= npc->health)
        npc->health = 0;
    else
        npc->health -= damage;

    std::cout << "Получено урона: " << damage << '\n';
    std::cout << "Текущее здоровье: " << npc->health << " HP\n";
}
