#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

class Player
{
private:
    std::string desc{""}; // randomly picked from pre-determined array
    std::string possibleDesc[5];
    int playerClass{0}; // 1 - Bulwark The Guardian, 2 - Aegis The Ravager, 3 - Ronan The Trickster
    int points{0};
    int ccCount{0};
    int sccCount{0};
    int gatesCompletedCount{0};
    std::vector<int> gatesCompleted;

    int xPos{0};
    int yPos{0};

public:
    Player(int playerClass, int startingPoints);
    std::string getDesc();
    void setDesc(std::string newDesc);

    int getPlayerClass();
    void setPlayerClass(int newPlayerClass);

    int getPoints();
    void setPoints(int newPoints);
    void adjustPoints(int amount); // can be positive or negative

    int getCueCardCount();
    void setCueCardCount(int newSupremeCueCardCount);

    int getSupremeCueCardCount();
    void setSupremeCueCardCount(int newSupremeCueCardCount);

    int getGatesCompletedCount();
    void setGatesCompletedCount(int newGatesCompletedCount);
    void incrementGatesCompletedCount();

    void resetGatesCompleted(); // resets count and vector
    void addCompletedGate(int gateNum);
    void randomlySetDesc();

    // player movement functions
    void setXPos(int newXPos);
    int getXPos();
    void setYPos(int newYPos);
    int getYPos();
    void move(char dir, std::vector<std::vector<std::string>> &map);
};

#endif