#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

/**
 * @class Character
 * @brief Abstract base class for all playable characters
 */
class Character {
protected:
    std::string name;
    std::string race;
    int attack;
    double attackChance;
    int defence;
    double defenceChance;
    int health;
    int strength;

public:
    Character(std::string raceName, int a, double ac, int d, double dc, int h, int s)
        : race(raceName), attack(a), attackChance(ac), defence(d), defenceChance(dc), health(h), strength(s) {}
    virtual ~Character() = default;

    virtual void printStats() const = 0;

    std::string getRace() const { return race; }
    int getAttack() const { return attack; }
    double getAttackChance() const { return attackChance; }
    int getDefence() const { return defence; }
    double getDefenceChance() const { return defenceChance; }
    int getHealth() const { return health; }
    int getStrength() const { return strength; }
};

#endif
