#ifndef STORE_H
#define STORE_H

#include <iostream>

class Store{
private:
    //variables 
    int itemChoice;
    int itemCount;
    int points{50}; // I set at 50 for testing, will change back for integration
    int cueCardCount{0};
    int supremeCardCount{0};
    
public:
    // declare the functions 
    bool StoreMenu();
    void PurchaseCC();
    void PurchaseSCC();
    void showInventory();

    // getters and setters
    int getPoints() const { return points; }
    void setPoints(int points); 
    
};

#endif
