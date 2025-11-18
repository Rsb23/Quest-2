#ifndef MAZE_H
#define MAZE_H
#include "store.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

void GenerateWarden(std::vector<std::vector<std::vector<bool>>> &Map);
void GenerateGates(std::vector<std::vector<std::vector<bool>>> &Map);
void GenerateFinish(std::vector<std::vector<std::vector<bool>>> &Map);
void FixWalls(std::vector<std::vector<std::vector<bool>>> &Map);
void GenerateMissingPaths(std::vector<std::vector<std::vector<bool>>> &Map, int &completed);
void GenerateMaze(std::vector<bool> &CurrentExits, std::vector<std::vector<std::vector<bool>>> &Map, std::vector<bool> &EligibleExits,int &x, int &y, std::vector<std::vector<int>> &pathStack);
void SelectTile(std::vector<bool> EligibleExits, std::vector<bool> CurrentExits, std::vector<std::vector<std::vector<bool>>> &Map, int &x, int &y, int &ForcedExit);
void DisplayTile(std::vector<bool> exits);
bool IsTileUninitialized(const std::vector<bool> &tile_exits);
void PlayerMove(int &move, int &PlayX, int &PlayY, std::vector<bool> CurrentExits, std::vector<std::vector<std::vector<bool>>> &Map, Store store);
std::vector<bool> CreateTile();
std::vector<bool> InitialTile();

#endif
