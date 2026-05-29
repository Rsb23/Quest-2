#pragma once
#include <vector>
#include <random>
#include <iostream>
using namespace std;

struct point{
     int x,y;
};


class Maze{
    private:
    vector<vector<vector<bool>>> maze;
    vector<point> pathStack;
    vector<point> selectionStack;
    point currentTile;
    point playerTile;

    bool IsInitialized(vector<bool>);
    void GenerateFinish();
    void GenerateWardens();
    void GenerateGates();
    void GenerateMaze();

    public:
    Maze();
    Maze(int, int);
    Maze(size_t);
    Maze(int, int,size_t);

    void DisplayTile(vector<bool>);
    void DisplayPlayerTile();
    vector<bool> GetPlayerTileStatus();
    void Move(char);
    void MoveBack();
    void ClearGate();
    void ClearWarden();

};