#include "CharacterFactory.h"

#include "Paladin.h"
#include "Warrior.h"
#include "Wizard.h"

// Enum - type data, который состоит из набора именованных констант.
// Его главная цель — сделать код более читаемым, понятным и безопасным, заменяя абстрактные числа понятными словами

// Документирование кода, Ограничение множества значений

// Enum - Имена констант «экспортируются» в окружающую область видимости.
// Автоматически и неявно приводится к целым числам (int).
// Безопасность типов низкая

// Enum class - Имена констант внутри перечисления.
// Не приводится к int автоматически. Требуется явное приведение.
// Безопасность типов высокая

/*Магические числа — это непонятные цифры в коде (например, 1, 404).
Замена их на именованные константы(enum) дает 3 плюса:
• Читаемость : код Status::Active понятен сразу, а 1 — нет.
• Легкость правки : значение меняется в одном месте, а не ищется по всему проекту.
• Безопасность : компилятор не даст сделать опечатку в имени, в отличие от случайной цифры.*/

std::unique_ptr<NPC> CharacterFactory::CreateCharacter(CharacterType type)
{
    switch (type)
    {
    case CharacterType::Warrior:
        return std::make_unique<Warrior>();
    case CharacterType::Wizard:
        return std::make_unique<Wizard>();
    case CharacterType::Paladin:
        return std::make_unique<Paladin>();
    default:
        return nullptr;
    }
}

std::unique_ptr<NPC> CharacterFactory::CreateCharacter(short choice)
{
    // Допустимые значения: от Warrior (1) до Count (не включая)
    if (choice < static_cast<short>(CharacterType::Warrior) ||
        choice >= static_cast<short>(CharacterType::Count))
    {
        return nullptr;
    }

    return CreateCharacter(static_cast<CharacterType>(choice));
}

std::string_view CharacterFactory::GetName(CharacterType type)
{
    switch (type)
    {
    case CharacterType::Warrior: return "Воин";
    case CharacterType::Wizard:  return "Волшебник";
    case CharacterType::Paladin: return "Паладин";
    default:                     return "?";
    }
}
