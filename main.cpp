/**
 * @file main.cpp
 * @brief Entry point. Manage board and player movement on squares.
 */
#include "Race.h"
#include "Board.h"
#include <iostream>
#include <string>

int main()
{
    int width = 8;
    int height = 4;
    Board board(width, height);

    int playerX = width/2;
    int playerY = height/2;

    int moveCount = 0;
    bool isNight = false;

    std::string command;


    std::shared_ptr<Character> player;
    int choice = 0;

    std::cout << "Please choose your character:\n";
    std::cout << "(1) Human\n(2) Elf\n(3) Hobbit\n(4) Dwarf\n";

    while (true) {
        std::cout << "Enter choice (1-4): ";
        std::cin >> choice;
        if (choice >= 1 && choice <= 4) break;
        std::cout << "Invalid choice, try again.\n";
        std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(); // clear newline

    switch (choice) {
    case 1: player = std::make_shared<Human>(); break;
    case 2: player = std::make_shared<Elf>(); break;
    case 3: player = std::make_shared<Hobbit>(); break;
    case 4: player = std::make_shared<Dwarf>(); break;
    }

    std::cout << "\nYour character's stats:\n";
    player->printStats();

    std::cout << " move with n/s/e/w, quit with q" << std::endl;
    while (true)
    {
        auto square = board.getSquare(playerX, playerY);
        square->printInfo();
        std::cout << "It is currently " << (isNight ? "NIGHT" : "DAY") << "." << std::endl;







        std::cout << "Command (n/s/e/w/q): ";
        std::getline(std::cin, command);

        if (command.empty())
            continue;

        char c = tolower(command[0]);
        bool moved = false;

        if (c == 'q')
            break;
        else if (c == 'n' && board.getSquare(playerX, playerY - 1)) {
            --playerY;
            moved = true;
        }
        else if (c == 's' && board.getSquare(playerX, playerY + 1)) {
            ++playerY;
            moved = true;
        }
        else if (c == 'e' && board.getSquare(playerX + 1, playerY)) {
            ++playerX;
            moved = true;
        }
        else if (c == 'w' && board.getSquare(playerX - 1, playerY)) {
            --playerX;
            moved = true;
        }
        else
            std::cout << "Invalid move." << std::endl;


        if (moved)
        {
            moveCount++;
            if (moveCount % 5 == 0)
            {
                isNight = !isNight;
                std::cout << "The time shifts! It is now " << (isNight ? "NIGHT" : "DAY") << "." << std::endl;
            }
        }
    }

    std::cout << "Game ended." << std::endl;
    return 0;
}
