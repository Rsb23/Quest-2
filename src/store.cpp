#include "store.h"

bool Store:: StoreMenu() {
    std::cout << "\nWelcome to the Store!" << std::endl;
    std::cout << "1: Purchase a Cue Card (10 pts)" << std::endl;
    std::cout << "2: Purchase a Supreme Cue Card (30 pts)" << std::endl;
    std::cout << "3: Check inventory" << std::endl;
    std::cout << "4: Exit" << std::endl;


    std::cout << "Enter your choice: ";
    std::cin >> itemChoice;
    
    if (itemChoice == 1){
        if (points < 10){
            std::cout << "Insufficient funds, please try again!" << std::endl;
        }
        
        else {
            PurchaseCC();
        }
        
        return true;
    }
    
    else if (itemChoice == 2){
        if (points < 30){
            std::cout << "Insufficient funds, please try again!" << std::endl;
        }
        
        else {
            PurchaseSCC();
        }
        
        return true;
    }
    
    else if (itemChoice == 3){
        showInventory();
        return true;
    }
    
    else if (itemChoice == 4){
        std::cout << "Thank you for visiting the store, come again soon!" << std::endl;
        return false;
    }

    else {
        std::cout << "Invalid choice, please try again" << std::endl;
        return true;
    }
}

void Store::PurchaseCC() {
    points -= 10;
    cueCardCount ++;
    
    std::cout << "You have purchased a Cue Card!" << std::endl;
    
    showInventory();
}

void Store::PurchaseSCC() {
    points -= 30;
    supremeCardCount ++;
    
    std::cout << "You have purchased a Supreme Cue Card!" << std::endl;
    
    showInventory();
}

void Store::showInventory() {
    std::cout << "\n ---- Inventory ---- " << std::endl;
    std::cout << "Points: " << points << std::endl;
    std::cout << "Cue Cards: " << cueCardCount << std::endl;
    std::cout << "Supreme Cue Cards: " << supremeCardCount << std::endl;
}

int main() 
{
    Store myStore;
    while (myStore.StoreMenu()) {
        char again;
        std::cout << "Return to store? (Y/N): ";
        std::cin >> again;
        
        if (again == 'n' || again == 'N') {
            std::cout << "Thank you for visiting the store, come again soon!" << std::endl;
            break;
        }
    }
    return 0;
}
