#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include "player.h"


class Store
{
private:
    // variables
    int itemChoice;
    points = player.getPoints();
    std::vector<int> numbers = {1, 2, 3, 4, 5, 7}
    
public:
    // declare the functions 
    bool StoreMenu();
    void PurchaseCC();
    void PurchaseSCC();
    void showInventory();

public:
    // declare the functi9ns
    void storeMenu(Player &player);
    void purchaseCC(Player &player);
    void purchaseSCC(Player &player);
    void showInventory(Player &player);
};

#endif
