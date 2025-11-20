#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

class Player
{
protected:
    int points{0};
    int ccCount{0};
    int sccCount{0};
    int gatesCompletedCount{0};
    int wardensCompletedCount{0};

    int xPos{0};
    int yPos{0};

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

    virtual void encounterGate(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY);
    virtual void encounterWarden(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY);

    // player movement functions
    void setXPos(int newXPos);
    int getXPos();
    void setYPos(int newYPos);
    int getYPos();
    void PlayerMove(char &move, int &PlayX, int &PlayY, std::vector<bool> CurrentExits, std::vector<std::vector<std::vector<bool>>> &Map, int &PrevX, int &PrevY);
};

#endif