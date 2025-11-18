#ifndef GATE_H
#define GATE_H

#include <string>

class Gate
{
protected:
    std::string prompt{""};
    int pointsValue{5};
    bool completed{false};
    int correctAnswer{-1};

public:
    // getters & setters
    std::string getPrompt();
    void setPrompt(std::string newPrompt);
    int getPointsValue();
    void setPointsValue(int newPointsValue);
    bool getCompleted();
    void setCompleted(bool newCompleted);
    int getCorrectAnswer();
    void setCorrectAnswer(int newCorrectAnswer);

    void loadPrompt();
};

#endif