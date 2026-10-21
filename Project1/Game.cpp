#include <iostream>
#include <windows.h>

#include "Player.h"

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Player player;

    std::cout << "Кем ты хочешь играть?\n";
    std::cout << "1 - Воин\n";
    std::cout << "2 - Волшебник\n";
    std::cout << "3 - Паладин\n";

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
