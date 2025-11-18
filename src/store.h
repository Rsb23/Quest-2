#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "player.h"


class Store
{
private:
    // variables
    int itemChoice;

public:
    // declare the functi9ns
    void storeMenu(Player &player);
    void purchaseCC(Player &player);
    void purchaseSCC(Player &player);
    void showInventory(const Player &player);
};

#endif
