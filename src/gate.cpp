#include "gate.h"

std::string Gate::getPrompt()
{
        return prompt;
}
void Gate::setPrompt(std::string newPrompt)
{
        prompt = newPrompt;
}
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

int Gate::getCorrectAnswer()
{
        return correctAnswer;
}

void Gate::setCorrectAnswer(int newCorrectAnswer)
{
        correctAnswer = newCorrectAnswer;
}

void Gate::loadPrompt()
{
        // seed RNG beforehand
        // min + (rand() % (max - min + 1))

        // choose 3 untruthful statements

        // choose 1 truthful statement
}