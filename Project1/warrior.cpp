#include "Warrior.h"

#include <iostream>
#include <utility>

Warrior::Warrior()
{
    className = "Воин";
    damage = 20;
    health = 30;
    armor = 15;
}

Warrior::Warrior(std::string name, unsigned int targetLvl) : Warrior()
{
    this->name = std::move(name);

    while (lvl < static_cast<short>(targetLvl))
        LvlUp();
}

void Warrior::Create()
{
    std::cout << "Вы создали воина!\n";
    std::cout << "Задайте имя игрока: ";
    std::cin >> name;

    if (weapons.empty())
    {
        Weapon weapon;
        weapon.damage = 1;
        weapon.name = "Кулаки";
        weapons.push_back(weapon);
    }

    GetInfo();
    GetWeapon();
}

void Warrior::GetInfo() const
{
    NPC::GetInfo();
    std::cout << "Сила: " << strength << '\n';
}

void Warrior::GetWeapon() const
{
    if (weapons.empty())
    {
        std::cout << "Оружие отсутствует.\n";
        return;
    }

    std::cout << name << " взял в руки оружие: " << weapons[0].name << '\n';
    std::cout << "Добавка к урону: " << weapons[0].damage << '\n';
}

void Warrior::Relaculate()
{
    NPC::Relaculate();
    damage += static_cast<unsigned int>(strength / 10);
    health += static_cast<unsigned int>(strength / 5);
}

Warrior::~Warrior()
{
    std::cout << name << " пал смертью храбрых\n";
}
