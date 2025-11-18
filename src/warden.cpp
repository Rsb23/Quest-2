#include "warden.h"

Warden::Warden()
{
        pointsValue = 15;
}

bool Warden::getIsTruthful()
{
        return isTruthful;
}

void Warden::setIsTruthful(bool inputIsTruthful)
{
        isTruthful = inputIsTruthful;
}

void Warden::assignTruthfulness()
{
        setIsTruthful(makeRandomNum(0, 1));
}

void Warden::loadPrompt(Player &_player, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
        int questionsCorrect{0};

        for (int i{0}; i < 3; i++)
        {
                int person{makeRandomNum(0, 6)}; // 0 - Tyler, 1 - Francis, 2 - Gaurav, 3 - Nosa, 4 - Liam, 5 - Stefan, 6 - Avneet
                int questionChoice{makeRandomNum(0, 2)};

                if (isTruthful)
                {
                        if (person == 0)
                        {
                                std::cout << "You ask: " << tylerQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << tylerAns[questionChoice] << "\n";
                        }
                        else if (person == 1)
                        {
                                std::cout << "You ask: " << francisQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << francisAns[questionChoice] << "\n";
                        }
                        else if (person == 2)
                        {
                                std::cout << "You ask: " << gauravQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << gauravAns[questionChoice] << "\n";
                        }
                        else if (person == 3)
                        {
                                std::cout << "You ask: " << nosaQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << nosaAns[questionChoice] << "\n";
                        }
                        else if (person == 4)
                        {
                                std::cout << "You ask: " << liamQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << liamAns[questionChoice] << "\n";
                        }
                        else if (person == 5)
                        {
                                std::cout << "You ask: " << stefanQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << stefanAns[questionChoice] << "\n";
                        }
                        else if (person == 6)
                        {
                                std::cout << "You ask: " << avneetQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << avneetAns[questionChoice] << "\n";
                        }

                        char res{'n'};

                        std::cout << "Is the Warden telling the truth (y/n)?: ";
                        std::cin >> res;

                        if (res == 'y')
                        {
                                std::cout << "That's correct!\n";
                                std::cout << "The Warden's decaying skin crumbles into a heap of dust, blown away in the passageway's breeze.\n";

                                std::cout << "Points Increase: +" << pointsValue << "pts\n";

                                Map[PlayX][PlayY][5] = 0;
                                setCompleted(true);
                                _player.adjustPoints(pointsValue);
                                questionsCorrect++;
                                continue;
                        }
                        else if (res == 'n')
                        {
                                std::cout << "That's incorrect\n!";
                                std::cout << "The Warden lets out a bellowing scream as the smell of decaying flesh arises from his mouth.\n";

                                std::cout << "Points Decrease: -25\% of current points = " << _player.getPoints() << "*" << "0.75 = " << std::floor(_player.getPoints() * 0.75f) << "\n";
                                _player.setPoints(std::floor(_player.getPoints() * 0.75f));
                        }
                        else
                        {
                                std::cout << "The Warden angers at your lack of a coherent response!\n";
                                break;
                        }
                }
                else
                {
                        if (person == 0)
                        {
                                std::cout << "You ask: " << tylerQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << tylerFalseAns[questionChoice] << "\n";
                        }
                        else if (person == 1)
                        {
                                std::cout << "You ask: " << francisQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << francisFalseAns[questionChoice] << "\n";
                        }
                        else if (person == 2)
                        {
                                std::cout << "You ask: " << gauravQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << gauravFalseAns[questionChoice] << "\n";
                        }
                        else if (person == 3)
                        {
                                std::cout << "You ask: " << nosaQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << nosaFalseAns[questionChoice] << "\n";
                        }
                        else if (person == 4)
                        {
                                std::cout << "You ask: " << liamQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << liamFalseAns[questionChoice] << "\n";
                        }
                        else if (person == 5)
                        {
                                std::cout << "You ask: " << stefanQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << stefanFalseAns[questionChoice] << "\n";
                        }
                        else if (person == 6)
                        {
                                std::cout << "You ask: " << avneetQuestions[questionChoice] << "\n";
                                std::cout << "The Warden responds: " << avneetFalseAns[questionChoice] << "\n";
                        }

                        char res{'n'};

                        std::cout << "Is the Warden telling the truth (y/n)?: ";
                        std::cin >> res;

                        if (res == 'n')
                        {
                                std::cout << "That's correct!\n";
                                std::cout << "The Warden's decaying skin crumbles into a heap of dust, blown away in the passageway's breeze.\n";

                                std::cout << "Points Increase: +" << pointsValue << "pts\n";

                                                                Map[PlayX][PlayY][5] = 0;
                                setCompleted(true);
                                _player.adjustPoints(pointsValue);
                                questionsCorrect++;
                                continue;
                        }
                        else if (res == 'y')
                        {
                                std::cout << "That's incorrect\n!";
                                std::cout << "The Warden lets out a bellowing scream as the smell of decaying flesh arises from his mouth.\n";

                                std::cout << "Points Decrease: -25\% of current points = " << _player.getPoints() << "*" << "0.75 = " << std::floor(_player.getPoints() * 0.75f) << "\n";
                                _player.setPoints(std::floor(_player.getPoints() * 0.75f));
                        }
                        else
                        {
                                std::cout << "The Warden angers at your lack of a coherent response!\n";
                                break;
                        }
                }
        }
}