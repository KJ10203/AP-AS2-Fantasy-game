Overview

This project implements a character-based board game system where players can choose from different fantasy races and navigate across a grid-based board. The game features day/night cycles that change every 5 moves.
Project Structure
Core Files
1. Board.h

    Purpose: Defines the game board and square system

    Key Components:

        Square class: Represents individual positions on the board

            Stores x,y coordinates

            Provides position information display

        Board class: Manages the 2D grid of squares

            Creates and maintains square objects using smart pointers

            Provides bounds-checked access to squares

            Handles board dimensions (width × height)

2. Character.h

    Purpose: Abstract base class for all playable characters

    Key Features:

        Defines common character attributes:

            Name, race, attack, defence, health, strength

            Attack and defence success probabilities

        Pure virtual function printStats() for character information display

        Getter methods for all attributes

3. Race.h

    Purpose: Implements specific character races inheriting from Character

    Available Races:

        Human: Balanced stats (Attack: 30, Health: 60, Strength: 100)

        Elf: High attack accuracy, low defence (Attack: 40, 100% hit chance)

        Hobbit: Defensive, high health (Health: 70, 2/3 defence chance)

        Dwarf: High strength, balanced combat (Strength: 130, 2/3 attack/defence)

4. main.cpp

    Purpose: Game entry point and main game loop

    Features:

        Board initialization (default: 8×4 grid)

        Character selection menu

        Movement system (N/S/E/W commands)

        Day/Night cycle tracking (changes every 5 moves)

        Continuous game loop until player quits

Game Mechanics
Character Selection

Players choose from 4 fantasy races, each with unique stat distributions:

    Different attack/defense values and probabilities

    Varied health and strength pools

    Race-specific strengths and weaknesses

Movement System

    Commands:

        n - Move North

        s - Move South

        e - Move East

        w - Move West

        q - Quit game

    Validation: Prevents movement outside board boundaries

Time System

    Tracks number of moves

    Alternates between DAY and NIGHT every 5 moves

    Time state displayed with position information

Technical Implementation
Design Patterns

    Factory Pattern: Character creation through race-specific constructors

    Smart Pointers: std::shared_ptr for automatic memory management

    Inheritance: Race classes derive from abstract Character base

    Encapsulation: Private member variables with public getters

Memory Management

    Uses std::shared_ptr for Square objects

    Automatic resource cleanup

    Safe object sharing between components



You can use this as base for devloping special effects in characters , combat mechanics or items , i will humanize this over the weekend.

