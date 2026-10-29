#pragma once

#include <string>
#include <string_view>

// Нумерация с 1, как и у CharacterType.
// Count — не оружие, а граница для перебора.
enum class WeaponType : short
{
    Fists = 1,
    Sword,
    Axe,
    Hammer,
    Count
};

struct Weapon
{
    std::string name{ "weapon" };
    unsigned int damage{ 1 };
};

// Название оружия для меню и вывода
std::string_view GetWeaponName(WeaponType type);

// Создаёт готовое оружие с нужным названием и уроном
Weapon CreateWeapon(WeaponType type);
