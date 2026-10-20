#include "Wizard.h"

#include <iostream>

Wizard::Wizard()
{
    className = "Волшебник";
    damage = 27;
    health = 21;
    armor = 10;
}

void Wizard::Create()
{
    std::cout << "Вы создали волшебника!\n";
    std::cout << "Задайте имя игрока: ";
    std::cin >> name;

    if (spells.empty())
    {
        Spell spell;
        spell.damage = 2;
        spell.name = "Вспышка";
        spells.push_back(spell);
    }

    GetInfo();
    LearnSpell();
}

void Wizard::GetInfo() const
{
    NPC::GetInfo();
    std::cout << "Интеллект: " << intellect << '\n';
}

void Wizard::LearnSpell() const
{
    if (spells.empty())
    {
        std::cout << "Заклинания отсутствуют.\n";
        return;
    }

    std::cout << name << " изучил заклинание: " << spells[0].name << '\n';
    std::cout << "Добавка к урону: " << spells[0].damage << '\n';
}

void Wizard::Relaculate()
{
    NPC::Relaculate();
    damage += static_cast<unsigned int>(intellect / 10);
}

Wizard::~Wizard()
{
    std::cout << name << " испускает дух\n";
}
