#include "gate.h"

std::string Gate::getPrompt(){
    return prompt;
}
void Gate::setPrompt(std::string newPrompt){
        prompt = newPrompt;
}
bool Gate::getPromptTruth(){
        return promptIsTrue;
}
void Gate::setPromptTruth(bool newTruth){
        promptIsTrue = newTruth;
}
int Gate::getPointsValue(){
        return pointsValue;
}
void Gate::setPointsValue(int newPointsValue){
        pointsValue = newPointsValue;
}
bool Gate::getCompleted(){
        return completed;
}
void Gate::setCompleted(bool newCompleted){
        completed = newCompleted;
}