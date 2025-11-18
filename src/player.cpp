#include "player.h"
#include "gate.h"
#include "warden.h"


// getters and setterse
std::string Player::getDesc(){
    return desc;
}

void Player::setDesc(std::string newDesc){
    desc = newDesc;
}

int Player::getPoints(){
    return points;
}

void Player::setPoints(int newPoints){
    points = newPoints;
}

void Player::adjustPoints(int amount){
    points += amount;
}

int Player::getCueCardCount(){
    return ccCount;
}

void Player::setCueCardCount(int newCueCardCount){
    ccCount = newCueCardCount;
}

int Player::getSupremeCueCardCount(){
    return sccCount;
}

void Player::setSupremeCueCardCount(int newSupremeCueCardCount){
    sccCount = newSupremeCueCardCount;
}

int Player::getGatesCompletedCount(){
    return gatesCompletedCount;
}

void Player::setGatesCompletedCount(int newGatesCompletedCount){
    gatesCompletedCount = newGatesCompletedCount;
}

void Player::incrementGatesCompletedCount(){
    gatesCompletedCount++;
}

int Player::getWardensCompletedCount(){
    return wardensCompletedCount;
}

void Player::setWardensCompletedCount(int newWardensCompletedCount){
    wardensCompletedCount = newWardensCompletedCount;
}

void Player::incrementWardensCompletedCount(){
    wardensCompletedCount++;
}

void Player::encounterGate(){
    std::cout << "You have encountered an old gate. It's strong, oak wood creaks in the breeze.\n";
    std::cout << "Embossed on the gate's ancient wood is a line of text: \n\n";

    Gate _gate;

    _gate.loadPrompt(*this);
}

void Player::encounterWarden(){
    std::cout << "You encounter a Warden guarding the passage. It's leathery skin groans under the stress of keeping it's diseased organs together.\n";
    std::cout << "The Warden asks you three questions: \n\n";

    Warden _warden;

    _warden.loadPrompt(*this);
}

// player movement functions
void Player::setXPos(int newXPos)
{
    xPos = newXPos;
}
int Player::getXPos()
{
    return xPos;
}
void Player::setYPos(int newYPos)
{
    yPos = newYPos;
}
int Player::getYPos()
{
    return yPos;
}
void Player::move(char dir, std::vector<std::vector<std::string>> &map)
{
    // "moves" character based on input, doesn't move if it detects a wall, and can be changed to start asking questions when detecting a guard
    if (dir == 'w')
    {
        if (map[xPos - 1][yPos] == "*")
        {
            std::cout << "There's a wall" << "\n";
        }
        else if (map[xPos - 1][yPos] == "X")
        {
            std::cout << "It's a guard!: (Placeholder question)" << "\n";
        }
        else
        {
            xPos--;
        }
    }
    else if (dir == 's')
    {
        if (map[xPos + 1][yPos] == "*")
        {
            std::cout << "There's a wall" << "\n";
        }
        else if (map[xPos + 1][yPos] == "X")
        {
            std::cout << "It's a guard!: (Placeholder question)" << "\n";
        }
        else
        {
            xPos++;
        }
    }
    else if (dir == 'a')
    {
        if (map[xPos][yPos - 1] == "*")
        {
            std::cout << "There's a wall" << "\n";
        }
        else if (map[xPos][yPos - 1] == "X")
        {
            std::cout << "It's a guard!: (Placeholder question)" << "\n";
        }
        else
        {
            yPos--;
        }
    }
    else if (dir == 'd')
    {
        if (map[xPos][yPos + 1] == "*")
        {
            std::cout << "There's a wall" << "\n";
        }
        else if (map[xPos][yPos + 1] == "X")
        {
            std::cout << "It's a guard: (Placeholder question)" << "\n";
        }
        else
        {
            yPos++;
        }
    }
    else
    {
        std::cout << "Invalid character entered" << "\n";
    }
}
