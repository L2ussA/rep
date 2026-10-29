#include "Weapon.h"

std::string_view GetWeaponName(WeaponType type)
{
    switch (type)
    {
    case WeaponType::Fists:  return "Кулаки";
    case WeaponType::Sword:  return "Меч";
    case WeaponType::Axe:    return "Топор";
    case WeaponType::Hammer: return "Молот";
    default:                 return "?";
    }
}

Weapon CreateWeapon(WeaponType type)
{
    Weapon weapon;
    weapon.name = std::string(GetWeaponName(type));

    switch (type)
    {
    case WeaponType::Fists:  weapon.damage = 1;  break;
    case WeaponType::Sword:  weapon.damage = 10; break;
    case WeaponType::Axe:    weapon.damage = 14; break;
    case WeaponType::Hammer: weapon.damage = 18; break;
    default:                 weapon.damage = 1;  break;
    }

    return weapon;
}
