#pragma once

#include "NPC.h"

#include <memory>
#include <string_view>

// Нумерация с 1, чтобы совпадала с пунктами меню и не сломала Player::Create(short).
// Count — не персонаж, а граница для перебора.
enum class CharacterType : short
{
    Warrior = 1,
    Wizard,
    Paladin,
    Count
};

class CharacterFactory
{
public:
    static std::unique_ptr<NPC> CreateCharacter(CharacterType type);

    // Принимает число из меню, проверяет диапазон и вызывает версию выше.
    static std::unique_ptr<NPC> CreateCharacter(short choice);

    static std::string_view GetName(CharacterType type);
};
