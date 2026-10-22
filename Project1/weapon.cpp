#include "Weapon.h"
#include <iostream>

Weapon::Weapon(std::string n, int damage, WeaponQuality q)
    : name(n), baseDamage(damage), quality(q) {
}

void Weapon::printDescription() const {
    std::cout << "Оружие: " << name << " (Базовый урон: " << baseDamage << ")\n";

    // Switch-case для обработки качества оружия
    switch (quality) {
    case WeaponQuality::Common:    std::cout << "Качество: Обычное. Без бонусов.\n"; break;
    case WeaponQuality::Uncommon:  std::cout << "Качество: Необычное. +5 к урону.\n"; break;
    case WeaponQuality::Rare:      std::cout << "Качество: Редкое. Повышает крит.\n"; break;
    case WeaponQuality::Epic:      std::cout << "Качество: Эпическое. Светящийся артефакт.\n"; break;
    case WeaponQuality::Legendary: std::cout << "Качество: ЛЕГЕНДАРНОЕ! Оружие богов!\n"; break;
    }
}
