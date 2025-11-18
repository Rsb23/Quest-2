#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

class Player
{
private:
    std::string desc{""}; // 1 - Bulwark The Guardian, 2 - Aegis The Ravager, 3 - Ronan The Trickster
    int points{0};
    int ccCount{0};
    int sccCount{0};
    int gatesCompletedCount{0};
    int wardensCompletedCount{0};

    int xPos{0};
    int yPos{0};

public:
    std::string getDesc();
    void setDesc(std::string newDesc);

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

    void encounterGate();
    void encounterWarden();

    // player movement functions
    void setXPos(int newXPos);
    int getXPos();
    void setYPos(int newYPos);
    int getYPos();
    void move(char dir, std::vector<std::vector<std::string>> &map);
    void PlayerMove(char &move, int &PlayX, int &PlayY, std::vector<bool> CurrentExits, std::vector<std::vector<std::vector<bool>>> &Map, int &PrevX, int &PrevY);
};

#endif