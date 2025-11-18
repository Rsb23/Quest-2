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
    int lives{5};
    int cueCardCount{0};
    int gatesCompleted{0};
    int points{0};

    int xPos{0};
    int yPos{0};

public:
    // Player();
    std::string getDesc();
    void setDesc(std::string newDesc);
    void randomlyPickDesc();
    int getLives();
    void setLives(int newLives);
    int getCueCardCount();
    void setCueCardCount(int newCueCardCount);
    int getGatesCompleted();
    void setGatesCompleted(int newGatesCompleted);
    void incrementGatesCompleted();
    void resetGatesCompleted();
    int getPoints();
    void setPoints(int newPoints);
    void adjustPoints(int amount); // can be positive or negative

    // player movement function
};

#endif