#include "map.h"

std::vector<std::vector<std::string>> Map::generateMap(int width, int height)
{
    std::vector<std::vector<std::string>> map(height, std::vector<std::string>(width));

    srand(time(0)); // seed RNG

    // Fill the border with '*' (walls) and all other spaces with '.'
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                map[i][j] = "*";
            }
            else
            {
                map[i][j] = ".";
            }
        }
    }

    // Generates a random position within walls
    int place = rand() % (height - 1);

    if (place == 0)
    {
        place = 1;
    }

    // Places one guard on the far wall based on the random position
    map[place][width - 1] = "X";

    return map;
}

void Map::displayMap(const std::vector<std::vector<std::string>> &map)
{
    for (const auto &row : map)
    {
        for (const auto &cell : row)
        {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}