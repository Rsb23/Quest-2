#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime> // for seeding RNG

class Map
{
public:
    std::vector<std::vector<std::string>> generateMap(int width, int height);
    void displayMap(const std::vector<std::vector<std::string>> &map);
};

#endif