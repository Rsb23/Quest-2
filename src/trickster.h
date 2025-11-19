#ifndef TRICKSTER_H
#define TRICKSTER_H

#include "player.h"

class Trickster : public Player
{
private:
    int defaultShadowShiftUses{5};

public:
    int getDefaultShadowShiftUses();
    void setDefaultShadowShiftUses(int newDefaultShadowShiftUses);

    void encounterGate(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY) override;
    void encounterWarden(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY) override;
};

#endif