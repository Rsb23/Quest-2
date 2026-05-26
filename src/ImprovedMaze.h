#pragma once
#include <vector>
#include <queue>
#include <random>
using namespace std;

//Implement Recursive Backtracking Algorithm

struct point{
    int x,y;
};


class Maze{
    private:
    vector<vector<vector<bool>>> maze;
    vector<point> pathStack;
    vector<point> selectionStack;
    point currentTile;

    bool QueryInitialization(vector<bool>);
    void GenerateWardens();
    void GenerateGates();

    public:
    Maze();
    void GenerateMaze();
    void DisplayTile();


};