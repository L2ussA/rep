#pragma once

#include <string>

class NPC
{
protected:
    std::string name{ "npc" };
    std::string className{ "NPC" };

    unsigned int damage{ 2 };
    unsigned int health{ 5 };
    short lvl{ 1 };
    unsigned int armor{ 2 };

private:
    bool isEnemy{ true };

public:
    NPC();

    unsigned int GetDamage() const;
    unsigned int GetHealth() const;
    void SetHealth(unsigned int health);

    // Каждый игровой класс сам реализует своё создание.
    virtual void Create() = 0;
    virtual void GetInfo() const;

    void LvlUp();
    virtual void Relaculate();

    virtual ~NPC() = default;

    friend void TakeDamage(NPC* npc, unsigned int damage);
};

void TakeDamage(NPC* npc, unsigned int damage);
