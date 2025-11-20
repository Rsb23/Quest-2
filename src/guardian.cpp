#include "guardian.h"
#include "gate.h"
#include "warden.h"
#include "player.h"

int Guardian::getLives()
{
    return lives;
}
void Guardian::setLives(int newLives)
{
    lives = newLives;
}

void Guardian::incrementLives()
{
    lives++;
}

void Guardian::decrementLives()
{
    lives--;
}

void Guardian::encounterGate(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
    std::cout << "You have encountered an old gate. It's strong, oak wood creaks in the breeze.\n";

    bool useCC{useCard(true)};

    if (useCC)
    {
        std::cout << "Wowowaaaw, you decided to use a cue card! The gate gets knocked down, its hinges snapping off in a flurry that ends in a cloud of dust\n";
        Map[PlayX][PlayY][4] = 0; // clear the gate from the map/maze

        this->setCueCardCount(this->getCueCardCount() - 1);
        this->incrementGatesCompletedCount();
    }
    else
    {
        std::cout << "Embossed on the gate's ancient wood is a line of text: \n\n";

        Gate _gate;
        _gate.loadPrompt(*this, Map, PlayX, PlayY);
    }
}

void Guardian::encounterWarden(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
    std::cout << "You encounter a Warden guarding the passage. It's leathery skin groans under the stress of keeping it's diseased organs together.\n";

    bool useCC{useCard(false)};

    if (useCC)
    {
        std::cout << "Wowowaaaw, you decided to use a supreme cue card! The warden falls to its knees as its flesh melts into dust\n";
        Map[PlayX][PlayY][5] = 0; // clear the warden from the map/maze

        this->setSupremeCueCardCount(this->getSupremeCueCardCount() - 1);
        this->incrementWardensCompletedCount();
    }
    else
    {
        std::cout << "The Warden asks you three questions: \n\n";

        Warden _warden;
        _warden.loadPrompt(*this, Map, PlayX, PlayY);
    }
}
