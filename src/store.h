#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "player.h"

class Store
{
private:
    int itemChoice;                 
    std::vector<int> numbers;  

    //functions for JUST the slot machine
    void drawSlotSquares(int number);
    int spinWheel(const std::vector<int> &numbers);
    int winCheck(int slot1, int slot2, int slot3);
    bool isNumber(const std::string &s);
    void playSlots(const std::vector<int> &numbers, int &points);

public:
    //functions for JUST the store
    void storeMenu(Player &player);
    void purchaseCC(Player &player);
    void purchaseSCC(Player &player);
    void showInventory(Player &player);
};

#endif
