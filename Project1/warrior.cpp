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
        std::cout << "Выберите оружие:\n";

        // Меню строится перебором enum: новое оружие появится здесь само
        for (short i = static_cast<short>(WeaponType::Fists);
             i < static_cast<short>(WeaponType::Count); ++i)
        {
            const WeaponType type = static_cast<WeaponType>(i);
            std::cout << i << " - " << GetWeaponName(type)
                      << " (урон +" << CreateWeapon(type).damage << ")\n";
        }

        short choice = 0;
        std::cout << ">> ";
        std::cin >> choice;

        if (choice < static_cast<short>(WeaponType::Fists) ||
            choice >= static_cast<short>(WeaponType::Count))
        {
            std::cout << "Такого оружия нет, берём кулаки.\n";
            choice = static_cast<short>(WeaponType::Fists);
        }

        weapons.push_back(CreateWeapon(static_cast<WeaponType>(choice)));
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
