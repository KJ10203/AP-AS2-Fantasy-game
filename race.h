#ifndef RACE_H
#define RACE_H

#include "Character.h"
#include <iostream>

/**
 * @class Human
 * @brief Human race
 */
class Human : public Character {
public:
    Human() : Character("Human", 30, 2.0/3.0, 20, 1.0/2.0, 60, 100) {}
    void printStats() const override {
        std::cout << "Race: Human\nAttack: 30\nAttack Chance: 2/3\nDefence: 20\nDefence Chance: 1/2\nHealth: 60\nStrength: 100\n";
    }
};

class Elf : public Character {
public:
    Elf() : Character("Elf", 40, 1.0, 10, 1.0/4.0, 40, 70) {}
    void printStats() const override {
        std::cout << "Race: Elf\nAttack: 40\nAttack Chance: 1\nDefence: 10\nDefence Chance: 1/4\nHealth: 40\nStrength: 70\n";
    }
};

class Hobbit : public Character {
public:
    Hobbit() : Character("Hobbit", 25, 1.0/3.0, 20, 2.0/3.0, 70, 85) {}
    void printStats() const override {
        std::cout << "Race: Hobbit\nAttack: 25\nAttack Chance: 1/3\nDefence: 20\nDefence Chance: 2/3\nHealth: 70\nStrength: 85\n";
    }
};

class Dwarf : public Character {
public:
    Dwarf() : Character("Dwarf", 30, 2.0/3.0, 20, 2.0/3.0, 50, 130) {}
    void printStats() const override {
        std::cout << "Race: Dwarf\nAttack: 30\nAttack Chance: 2/3\nDefence: 20\nDefence Chance: 2/3\nHealth: 50\nStrength: 130\n";
    }
};

#endif
