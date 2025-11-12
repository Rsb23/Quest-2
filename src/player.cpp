#include "player.h"

// getters and setters
void Player::setXPos(int newXPos)
{
    xPos = newXPos;
}
int Player::getXPos()
{
    return xPos;
}
void Player::setYPos(int newYPos)
{
    yPos = newYPos;
}
int Player::getYPos()
{
    return yPos;
}
void Player::move(std::string dir, std::vector<std::vector<std::string>> &map)
{
    // "moves" character based on input, doesn't move if it detects a wall, and can be changed to start asking questions when detecting a guard
    if (dir == "w")
    {
        if (map[xPos - 1][yPos] == "*")
        {
            std::cout << "There's a wall" << "\n";
        }
        else if (map[xPos - 1][yPos] == "X")
        {
            std::cout << "It's a guard!: (Placeholder question)" << "\n";
        }
        else
        {
            xPos--;
        }
    }
    else if (dir == "s")
    {
        if (map[xPos + 1][yPos] == "*")
        {
            std::cout << "There's a wall" << "\n";
        }
        else if (map[xPos + 1][yPos] == "X")
        {
            std::cout << "It's a guard!: (Placeholder question)" << "\n";
        }
        else
        {
            xPos++;
        }
    }
    else if (dir == "a")
    {
        if (map[xPos][yPos - 1] == "*")
        {
            std::cout << "There's a wall" << "\n";
        }
        else if (map[xPos][yPos - 1] == "X")
        {
            std::cout << "It's a guard!: (Placeholder question)" << "\n";
        }
        else
        {
            yPos--;
        }
    }
    else if (dir == "d")
    {
        if (map[xPos][yPos + 1] == "*")
        {
            std::cout << "There's a wall" << "\n";
        }
        else if (map[xPos][yPos + 1] == "X")
        {
            std::cout << "It's a guard: (Placeholder question)" << "\n";
        }
        else
        {
            yPos++;
        }
    }
    else
    {
        std::cout << "Invalid character entered" << "\n";
    }
}