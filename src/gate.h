#ifndef GATE_H
#define GATE_H

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

class Gate
{
protected:
    int pointsValue{5};
    bool completed{false};

    std::vector<std::string> tylerQuestions = {"Completed two years of training in Classical French Cuisine", "Played Acoustic guitar for seven years", "Has six pets split across two houses"};
    std::vector<std::string> francisQuestions = {"Can speak broken Arabic and Spanish", "Mains Kirby in Super Smash Bros", "Listened to Spotify for 36K minutes last year"};
    std::vector<std::string> gauravQuestions = {"Played the alto saxophone for five years", "Has never broken a bone", "Can speak tamil fluently"};
    std::vector<std::string> nosaQuestions = {"Has lived in three countries", "Played semi-professional soccer for nearly two years", "Can play more than two instruments"};
    std::vector<std::string> liamQuestions = {"Used to own chickens and quails", "One of their hobbies is blacksmithing", "Owns five 3D printers, one of which can print chocolate"};
    std::vector<std::string> stefanQuestions = {"Plays self-taught piano", "Did track and powerlifting for five years", "Built his own PC with the help of his friends"};
    std::vector<std::string> avneetQuestions = {"Played volleyball for seven years", "Is from Toronto", "Their younger siblings are fraternal twins"};

public:
    // getters & setters
    int getPointsValue();
    void setPointsValue(int newPointsValue);
    bool getCompleted();
    void setCompleted(bool newCompleted);

    int makeRandomNum(int min, int max);
    void loadPrompt(Player &_player, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY);
};

#endif