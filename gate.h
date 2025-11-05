#ifndef GATE_H
#define GATE_H

#include <string>

class Gate{
private: 
    std::string prompt {""};
    bool promptIsTrue {true};
    int pointsValue {10};
    bool completed {false};
public:
    std::string getPrompt();
    void setPrompt(std::string newPrompt);
    bool getPromptTruth();
    void setPromptTruth(bool newTruth);
    int getPointsValue();
    void setPointsValue(int newPointsValue);
    bool getCompleted();
    void setCompleted(bool newCompleted);
};

#endif