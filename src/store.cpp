#include "store.h"

void Store::storeMenu()
{
    while (true)
    {
        // gives user options to choose from
        std::cout << "\nWelcome to the Store!" << std::endl;
        std::cout << "1: Purchase a Cue Card (10 pts)" << std::endl;
        std::cout << "2: Purchase a Supreme Cue Card (30 pts)" << std::endl;
        std::cout << "3: Check inventory" << std::endl;
        std::cout << "4: Exit\n" << std::endl;

        //prompts user for choice
        std::cout << "Enter your choice: ";
        std::cin >> itemChoice;

        // case checks bring the user back to the store after every function
        if (itemChoice == 1)
        {
            if (points < 10)
            {
                std::cout << "Insufficient funds, please try again!" << std::endl;
            }

            else
            {
                purchaseCC();
            }
        }
        else if (itemChoice == 2)
        {
            if (points < 30)
            {
                std::cout << "Insufficient funds, please try again!" << std::endl;
            }

            else
            {
                purchaseSCC();
            }
        }
        else if (itemChoice == 3)
        {
            showInventory();
        }
        else if (itemChoice == 4)
        {
            std::cout << "Thank you for visiting the store, come again soon!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid choice, please try again" << std::endl;
        }
    }
}

void Store::purchaseCC()
{
    points -= 10;
    cueCardCount++;

    std::cout << "You have purchased a Cue Card!" << std::endl;

    showInventory();
}

void Store::purchaseSCC()
{
    points -= 30;
    supremeCardCount++;

    std::cout << "You have purchased a Supreme Cue Card!" << std::endl;

    showInventory();
}

void Store::showInventory()
{
    std::cout << "\n ---- Inventory ---- " << std::endl;
    std::cout << "Points: " << points << std::endl;
    std::cout << "Cue Cards: " << cueCardCount << std::endl;
    std::cout << "Supreme Cue Cards: " << supremeCardCount << std::endl;
}

int main()
{
    Store myStore;
    myStore.storeMenu();

    return 0;
}
