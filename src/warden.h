#ifndef WARDEN_H
#define WARDEN_H

#include "gate.h"
#include "player.h"
#include <cmath>

class Warden : public Gate
{
private:
    bool isTruthful{false};

    std::vector<std::string> tylerQuestions = {"What did Tyler complete two years of training for?", "Tyler played what for seven years?", "Tyler has how many pets split across two houses?"};
    std::vector<std::string> tylerAns = {"Classical French Cuisine", "Acoustic Guitar", "Six"};
    std::vector<std::string> tylerFalseAns = {"Karate", "Cello", "Four"};

    std::vector<std::string> francisQuestions = {"Francis can speak broken Arabic and what?", "francis mains what character in Super Smash Bros", "Francis listened to what for 36K minutes last year"};
    std::vector<std::string> francisAns = {"Spanish", "Kirby", "Spotify"};
    std::vector<std::string> francisFalseAns = {"Greek", "Pikachu", "Apple Music"};

    std::vector<std::string> gauravQuestions = {"Gaurav played what instrument for five years", "Gaurav has never broken a bone, is this true?", "Gaurav can speak what language fluently"};
    std::vector<std::string> gauravAns = {"Alto Saxophone", "Yes", "Tamil"};
    std::vector<std::string> gauravFalseAns = {"Trumpet", "No", "Bengali"};

    std::vector<std::string> nosaQuestions = {"Nosa has lived in how many countries?", "Nosa played what sport for nearly two years?", "Nosa can play more than how many instruments?"};
    std::vector<std::string> nosaAns = {"Three", "Semi-Professional Soccer", "Two"};
    std::vector<std::string> nosaFalseAns = {"Two", "Semi-Professional Rugby", "Three"};

    std::vector<std::string> liamQuestions = {"Liam used to own what animals?", "One of Liam's hobbies is what?", "Liam owns five 3D printers, one of which can print what material?"};
    std::vector<std::string> liamAns = {"Chickens and quails", "Blacksmithing", "Chocolate"};
    std::vector<std::string> liamFalseAns = {"Cows and horses", "Welding", "ABS Plastic"};

    std::vector<std::string> stefanQuestions = {"Stefan plays self-taught what?", "Stefan did what sports for five years?", "Stefan built his own what?"};
    std::vector<std::string> stefanAns = {"Piano", "Track and powerlifting", "PC"};
    std::vector<std::string> stefanFalseAns = {"Guitar", "Wrestling and track", "Bookcase"};

    std::vector<std::string> avneetQuestions = {"Avneet played what sport for seven years?", "Avneet is from where?", "Avneet's younger siblings are what?"};
    std::vector<std::string> avneetAns = {"Volleyball", "Toronto", "Fraternal Twins"};
    std::vector<std::string> avneetFalseAns = {"Hockey", "Quebec City", "Twins"};

public:
    Warden(); // constructor used for setting points value
    // getters & setters
    bool getIsTruthful();
    void setIsTruthful(bool inputIsTruthful);

    void assignTruthfulness();

    void loadPrompt(Player &_player, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY);
};

#endif