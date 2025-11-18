#include "gate.h"
#include "player.h"

int Gate::getPointsValue()
{
        return pointsValue;
}
void Gate::setPointsValue(int newPointsValue)
{
        pointsValue = newPointsValue;
}
bool Gate::getCompleted()
{
        return completed;
}
void Gate::setCompleted(bool newCompleted)
{
        completed = newCompleted;
}
int Gate::makeRandomNum(int min, int max){
    srand(time(0));  // seed RNG
    return (min + (rand() % (max - min + 1)));
}
void Gate::loadPrompt(Player &_player)
{
    while (true){
        int person {makeRandomNum(0, 6)};  // 0 - Tyler, 1 - Francis, 2 - Gaurav, 3 - Nosa, 4 - Liam, 5 - Stefan, 6 - Avneet
        int questionChoice {makeRandomNum(0, 2)};
                
        if (person == 0){
                std::cout << tylerQuestions[questionChoice] << "\n";
        }
        else if (person == 1){
                std::cout << francisQuestions[questionChoice] << "\n";
        }
        else if (person == 2){
                std::cout << gauravQuestions[questionChoice] << "\n";
        }
        else if (person == 3){
                std::cout << nosaQuestions[questionChoice] << "\n";
        }
        else if (person == 4){
                std::cout << liamQuestions[questionChoice] << "\n";
        }
        else if (person == 5){
                std::cout << stefanQuestions[questionChoice] << "\n";
        }
        else if (person == 6){
                std::cout << avneetQuestions[questionChoice] << "\n";
        }
        
        while (true){
                int response {-1};

                std::cout << "What person said this? (Tyler (0), Francis (1), Gaurav (2), Nosa (3), Liam (4), Stefan (5), or Avneet (6))?: ";
                std::cin >> response;

                if (response){
                        if (response == questionChoice){
                                std::cout << "That's correct!\n";
                                std::cout << "The old door swings open revealing another passage\n";

                                std::cout << "Points Increase: +" << pointsValue << "pts\n";
                                
                                setCompleted(true);
                                _player.adjustPoints(pointsValue);
                                break;
                        }
                        else {
                                std::cout << "That's incorrect\n!";
                                std::cout << "The sturdy door remains closed\n";

                                std::cout << "Points Decrease: -1pt\n";
                                _player.adjustPoints(-1);
                        }
                }
                else{
                        std::cout << "Please enter a response!\n";
                        continue;
                }
        }
    }
    
}