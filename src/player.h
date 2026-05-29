#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "maze.h"
class Player
{
protected:
    int points{0};
    int ccCount{0};
    int sccCount{0};
    int gatesCompletedCount{0};
    int wardensCompletedCount{0};

public:
    int getPoints();
    void setPoints(int newPoints);
    void adjustPoints(int amount); // can be positive or negative

    int getCueCardCount();
    void setCueCardCount(int newCueCardCount);

    int getSupremeCueCardCount();
    void setSupremeCueCardCount(int newSupremeCueCardCount);

    int getGatesCompletedCount();
    void setGatesCompletedCount(int newGatesCompletedCount);

    void incrementGatesCompletedCount();

    int getWardensCompletedCount();
    void setWardensCompletedCount(int newWardensCompletedCount);

    void incrementWardensCompletedCount();

    bool useCard(bool isGate);

    virtual void encounterGate(Maze &maze);
    virtual void encounterWarden(Maze &maze);
};

#endif