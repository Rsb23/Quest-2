#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>

void drawSlotSquares(int number) {
    std::cout << "+---+" << std::endl; //top border
    std::cout << "|" << number << "|" << std::endl; //middle of the box with number and sides
    std::cout << "+---+" << std::endl; //bottom border
} 



int spinWheel(const std::vector<int> &numbers) {
    int randomIndex = rand() % numbers.size();  
    return numbers[randomIndex];
}  


int winCheck(int slot1, int slot2, int slot3){
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

bool isNumber(std::string s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return !s.empty();
}

void playSlots(const std::vector<int> &numbers, int &points) {
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

int main()
{
    std::srand(std::time(0));
    std::vector<int> numbers = {1, 2, 3, 4, 5, 7};
    
    int points = 100; // TESTING PURPOSES!!!!!!!!!! ******** CHANGE BEFORE INTEGRATION *******

    int choice;
    std::string choiceInput;
    
    char answer1, answer2;
    
    while (true) {
        std::cout << "\nWelcome to the Slot Machine!" << std::endl;
        std::cout << "1: View point count" << std::endl;
        std::cout << "2: Play Slots" << std::endl;
        std::cout << "3: Exit" << std::endl;
        
        std::cout << "Enter your choice: ";
        std::cin >> choiceInput;

        if (!isNumber(choiceInput)) {
            std::cout << "Invalid choice, try again" << std::endl;
            continue; 
        }

        choice = stoi(choiceInput);

        
        if (choice == 1) {
            std::cout << "\nCurrent points: " << points << std::endl;
        }
        
        else if (choice == 2) {
            char playAgain = 'Y';
            
            while (playAgain == 'y' || playAgain == 'Y'){
                playSlots(numbers, points);
            
                if (points <= 0) {
                    std::cout << "You're out of points! Returning to menu" << std::endl;
                    break;
                }
            
                std::cout << "Would you like to play again? (Y/N): ";
                std::cin >> playAgain;
            }
        }
        
        else if (choice == 3) {
            std::cout << "\nAre you sure? 99% of gamblers quit before they win big ;)" << std::endl;
            std::cout << "Type Y to exit, type N to go back to the slot machine menu:";
            std::cin >> answer1;
            
            if (answer1 == 'N' || answer1 == 'n') {
                continue;
            }
            
            else if (answer1 == 'Y' || answer1 == 'y'){
                std::cout << "\nAre you 100% sure?? You could be one spin away from a Jackpot!" << std::endl;
                std::cout << "Type Y to exit, type N to go back to the slot machine menu: ";
                std::cin >> answer2;
                
                if (answer2 == 'N' || answer2 == 'n') {
                    continue;
                }
                
                else if (answer2 == 'Y' || answer2 == 'y') {
                    std::cout << "\nThanks for playing, come again soon!" << std::endl;
                    break;
                }
            }
        }
        
        else {
            std::cout << "Invalid choice, try again" << std::endl;
        }
    } 

    return 0;
}
