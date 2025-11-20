#ifndef RAVAGER_H
#define RAVAGER_H

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

    void encounterGate(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY) override;
    void encounterWarden(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY) override;

    Ravager(); // constructor, asks player if they want CC or SCC
};

#endif