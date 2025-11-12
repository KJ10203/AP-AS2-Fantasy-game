/**
 * @file Board.h
 * @brief Header file for the Board and Square classes.
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <iostream>

/**
 * @class Square
 * @brief Represents a single square on the board.
 */
class Square
{
private:
    int x;
    int y;

public:
    /**
     * @brief Constructor.
     * @param x_ X position of the square.
     * @param y_ Y position of the square.
     */
    Square(int x_, int y_) : x(x_), y(y_) {}

    /**
     * @brief Print info about this square.
     */
    void printInfo() const
    {
        std::cout << "You are at square (" << x << ", " << y << ")." << std::endl;
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

/**
 * @class Board
 * @brief Manages a 2D grid of Square objects using smart pointers.
 */
class Board
{
private:
    int width;
    int height;
    std::vector<std::vector<std::shared_ptr<Square>>> grid;

public:
    /**
     * @brief Constructor initializes board of given width and height.
     * @param width_ Number of columns.
     * @param height_ Number of rows.
     */
    Board(int width_, int height_) : width(width_), height(height_)
    {
        // Pseudo-code:
        // For each row from 0 to height-1:
        //   For each col from 0 to width-1:
        //     Create new Square using std::make_shared and add to grid
        grid.resize(height);
        for (int y = 0; y < height; ++y)
        {
            grid[y].resize(width);
            for (int x = 0; x < width; ++x)
            {
                grid[y][x] = std::make_shared<Square>(x, y);
            }
        }
    }

    /**
     * @brief Returns pointer to square at (x, y) or nullptr if out of bounds.
     */
    std::shared_ptr<Square> getSquare(int x, int y) const
    {
        if (x < 0 || x >= width || y < 0 || y >= height)
            return nullptr;
        return grid[y][x];
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

#endif // BOARD_H
