#include "store.h"

void Store::drawSlotSquares(int number) {
    std::cout << "+---+" << std::endl; //top border
    std::cout << "|" << number << "|" << std::endl; //middle of the box with number and sides
    std::cout << "+---+" << std::endl; //bottom border
} 

int Store::spinWheel(const std::vector<int> &numbers) {
    int randomIndex = rand() % numbers.size();  
    return numbers[randomIndex];
}  


int Store::winCheck(int slot1, int slot2, int slot3){
    // 3 matches - jackpot
    if (slot1 == slot2 && slot2 == slot3) {
        if (slot1 == 7) {
            std::cout << "\nJACKPOT!! = 5x Win!" << std::endl;
            return 5;
        }
        else {
            std::cout << "\nThree of a kind = 2x Win!" << std::endl;
            return 2;
        }
    }
    // 2 matches - pair
    else if (slot1 == slot2 || slot1 == slot3 || slot2 == slot3){
        std::cout << "\nTwo of a kind = 1x Win!" << std::endl;
        return 1;
    }
    // no matches
    else {
        std::cout << "No matches" << std::endl;
        return 0;
    }
}

bool Store::isNumber(const std::string s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return !s.empty();
}

void Store::playSlots(const std::vector<int> &numbers, int &points) {
    std::string betInput;
    int pointsBet;

    std::cout << "\nPlace your bet: ";
    std::cin >> betInput;
    
    if (!isNumber(betInput)){
        std::cout << "Invalid input, please try again" << std::endl;
        return;
    }
    pointsBet = stoi(betInput);
    
    if (pointsBet > points) {
        std::cout << "Insufficient funds, you only have " << points << " points\n";
        return;
    }
    
    else if (pointsBet <= 0) {
        std::cout << "Bet must be greater than 0\n";
        return;
    }
    
    points -= pointsBet;

    int slot1 = spinWheel(numbers);
    int slot2 = spinWheel(numbers);
    int slot3 = spinWheel(numbers);

    std::cout << "\nResults:\n";
    std::cout << "+---+" << "   " << "+---+" << "   " << "+---+" << std::endl;
    std::cout << "| " << slot1 << " |" << "   " 
              << "| " << slot2 << " |" << "   "
              << "| " << slot3 << " |" << std::endl;
    std::cout << "+---+" << "   " << "+---+" << "   " << "+---+" << std::endl;

    int multiplier = winCheck(slot1, slot2, slot3);

    if (multiplier == 0) {
        std::cout << "Tough luck. You lost " << pointsBet << " points :(\n";
    } 
    
    else {
        int payout = pointsBet * multiplier; 
        std::cout << "You won " << payout << " points!\n";
        points += payout;
    }

    std::cout << "You now have " << points << " points\n";

    if (points <= 0) {
        std::cout << "Insufficient funds! Try again later\n";
    }
}

void Store::storeMenu(Player &player)
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 7};
    
    while (true)
    {
        // gives user options to choose from
        std::cout << "\nWelcome to the Store!" << std::endl;
        std::cout << "1: Purchase a Cue Card (10 pts)" << std::endl;
        std::cout << "2: Purchase a Supreme Cue Card (30 pts)" << std::endl;
        std::cout << "3: Check inventory" << std::endl;
        std::cout << "4: Play Slot Machine" << std::endl;
        std::cout << "5: Exit\n" << std::endl;


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
            
        else if (itemChoice == 4){
            char playAgain = 'Y';

            while (playAgain == 'Y' || playAgain == 'y') {
                int points = player.getPoints(); 
                playSlots(numbers, points);
        
                player.setPoints(points);        

                if (player.getPoints() <= 0) {
                    std::cout << "You're out of points!" << std::endl;
                    break;
                }
                
                std::cout << "Do you want to play again? (Y/N): ";
                std::cin >> playAgain;
            }
        }
        
        else if (itemChoice == 5)
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
