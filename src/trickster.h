#ifndef TRICKSTER_H
#define TRICKSTER_H
#pragma once

#include "player.h"

class Trickster : public Player
{
private:
    int defaultShadowShiftUses{5};

public:
    int getDefaultShadowShiftUses();
    void setDefaultShadowShiftUses(int newDefaultShadowShiftUses);

    void encounterGate(Maze &maze) override;
    void encounterWarden(Maze &maze) override;
};

#endif