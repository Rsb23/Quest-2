#include "store.h"

void Store::storeMenu(Player &player)
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
            if (player.getPoints() < 10)
            {
                std::cout << "Insufficient funds, please try again!" << std::endl;
            }
            else
            {
                purchaseCC(player);
            }
        }
            
        else if (itemChoice == 2)
        {
            if (player.getPoints() < 30)
            {
                std::cout << "Insufficient funds, please try again!" << std::endl;
            }

            else
            {
                purchaseSCC(player);
            }
        }
            
        else if (itemChoice == 3)
        {
            showInventory(player);
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

void Store::purchaseCC(Player &player)
{
    player.adjustPoints(-10);
    player.setCueCardCount(player.getCueCardCount() + 1);

    std::cout << "You have purchased a Cue Card!" << std::endl;

    showInventory(player);
}

void Store::purchaseSCC(Player &player)
{
    player.adjustPoints(-30);
    player.setSupremeCueCardCount(player.getSupremeCueCardCount() + 1);

    std::cout << "You have purchased a Supreme Cue Card!" << std::endl;

    showInventory(player);
}

void Store::showInventory(Player &player)
{
    std::cout << "\n ---- Inventory ---- " << std::endl;
    std::cout << "Points: " << player.getPoints() << std::endl;
    std::cout << "Cue Cards: " << player.getCueCardCount() << std::endl;
    std::cout << "Supreme Cue Cards: " << player.getSupremeCueCardCount() << std::endl;
}