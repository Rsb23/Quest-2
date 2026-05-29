#ifndef RAVAGER_H
#define RAVAGER_H
#pragma once

#include "player.h"
#include <iostream>

class Ravager : public Player
{
private:
    int defaultCC{3};
    int defaultSCC{1};

public:
    int getDefaultCC();
    void setDefaultCC(int newDefaultCC);

    int getDefaultSCC();
    void setDefaultSCC(int newDefaultSCC);

    void encounterGate(Maze &maze) override;
    void encounterWarden(Maze &maze) override;

    Ravager(); // constructor, asks player if they want CC or SCC
};

#endif