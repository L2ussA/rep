#include <iostream>
#include <windows.h>

#include "CharacterFactory.h"
#include "Player.h"

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Player player;

    std::cout << "Кем ты хочешь играть?\n";

    // Меню строится перебором enum: новый персонаж появится здесь сам
    for (short i = static_cast<short>(CharacterType::Warrior);
         i < static_cast<short>(CharacterType::Count); ++i)
    {
        std::cout << i << " - "
                  << CharacterFactory::GetName(static_cast<CharacterType>(i)) << '\n';
    }

    short choice = 0;
    std::cout << ">> ";
    std::cin >> choice;

    if (!player.Create(choice))
    {
        std::cout << "Такого героя нет!\n";
        return 0;
    }

    std::cout << "\nПроверка получения урона:\n";
    TakeDamage(player.GetCharacter(), 5);
    
    return 0;
}
