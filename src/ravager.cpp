#include "ravager.h"
#include "gate.h"
#include "warden.h"
#include "player.h"

int Ravager::getDefaultCC()
{
    return defaultCC;
}
void Ravager::setDefaultCC(int newDefaultCC)
{
    defaultCC = newDefaultCC;
}

int Ravager::getDefaultSCC()
{
    return defaultSCC;
}
void Ravager::setDefaultSCC(int newDefaultSCC)
{
    defaultSCC = newDefaultSCC;
}

Ravager::Ravager()
{
    while (true)
    {
        std::cout << "As a ravager you can either get " << defaultCC << " cue cards OR " << defaultSCC << " supreme cue cards.\n";
        std::cout << "Please make a selection (c/s): ";

        char res{'c'};
        std::cin >> res;

        if (res == 'c')
        {
            defaultSCC = 0;
            ccCount = defaultCC;
            break;
        }
        else if (res == 's')
        {
            defaultCC = 0;
            sccCount = defaultSCC;
            break;
        }
        else
        {
            std::cout << "Please make a valid selection!\n";
        }
    }
}

void Ravager::encounterGate(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY) 
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

void Ravager::encounterWarden(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
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