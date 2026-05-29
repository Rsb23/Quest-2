#include "player.h"
#include "gate.h"
#include "warden.h"
#include "store.h"
#include "maze.h"

// getters and setters
int Player::getPoints()
{
    return points;
}

void Player::setPoints(int newPoints)
{
    points = newPoints;
}

void Player::adjustPoints(int amount)
{
    points += amount;
}

int Player::getCueCardCount()
{
    return ccCount;
}

void Player::setCueCardCount(int newCueCardCount)
{
    ccCount = newCueCardCount;
}

int Player::getSupremeCueCardCount()
{
    return sccCount;
}

void Player::setSupremeCueCardCount(int newSupremeCueCardCount)
{
    sccCount = newSupremeCueCardCount;
}

int Player::getGatesCompletedCount()
{
    return gatesCompletedCount;
}

void Player::setGatesCompletedCount(int newGatesCompletedCount)
{
    gatesCompletedCount = newGatesCompletedCount;
}

void Player::incrementGatesCompletedCount()
{
    gatesCompletedCount++;
}

int Player::getWardensCompletedCount()
{
    return wardensCompletedCount;
}

void Player::setWardensCompletedCount(int newWardensCompletedCount)
{
    wardensCompletedCount = newWardensCompletedCount;
}

void Player::incrementWardensCompletedCount()
{
    wardensCompletedCount++;
}

bool Player::useCard(bool isGate)
{
    if (getPoints() < -5)
    {
        std::cout << "You don't have any more points!\nYou Lose! :(\n";
        return 0;
    }

    if (isGate && this->getCueCardCount() > 0)
    {
        std::cout << "You have " << this->getCueCardCount() << " cue cards\n";
        std::cout << "Do you want to use a cue card to unlock the gate (y/n)?: ";

        char res{'n'};
        std::cin >> res;

        if (res == 'y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (!isGate && this->getSupremeCueCardCount() > 0)
    {
        std::cout << "You have " << this->getSupremeCueCardCount() << " supreme cue cards\n";
        std::cout << "Do you want to use a supreme cue card to unlock the warden (y/n)?: ";

        char res{'n'};
        std::cin >> res;

        if (res == 'y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void Player::encounterGate(Maze &maze)
{
    std::cout << "You have encountered an old gate. It's strong, oak wood creaks in the breeze.\n";

    bool useCC{useCard(true)};

    if (useCC)
    {
        std::cout << "Wowowaaaw, you decided to use a cue card! The gate gets knocked down, its hinges snapping off in a flurry that ends in a cloud of dust\n";
        maze.ClearGate();// clear the gate from the map/maze

        this->setCueCardCount(this->getCueCardCount() - 1);
        this->incrementGatesCompletedCount();
    }
    else
    {
        std::cout << "Embossed on the gate's ancient wood is a line of text: \n\n";

        Gate _gate;
        _gate.loadPrompt(*this, maze);
    }
}

void Player::encounterWarden(Maze &maze)
{
    std::cout << "You encounter a Warden guarding the passage. It's leathery skin groans under the stress of keeping it's diseased organs together.\n";

    bool useCC{useCard(false)};

    if (useCC)
    {
        std::cout << "Wowowaaaw, you decided to use a supreme cue card! The warden falls to its knees as its flesh melts into dust\n";
        maze.ClearWarden(); // clear the warden from the map/maze

        this->setSupremeCueCardCount(this->getSupremeCueCardCount() - 1);
        this->incrementWardensCompletedCount();
    }
    else
    {
        std::cout << "The Warden asks you three questions: \n\n";

        Warden _warden;
        _warden.loadPrompt(*this, maze);
    }
}