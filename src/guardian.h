#ifndef GUARDIAN_H
#define GUARDIAN_H
#pragma once
#include "player.h"

class Guardian : public Player
{
private:
    int lives{3}; // 1 life = prevents loss of points for one incorrect question/answer
public:
    int getLives();
    void setLives(int newLives);

    void incrementLives();
    void decrementLives();

    void encounterGate(Maze &maze) override;
    void encounterWarden(Maze &maze) override;
};

#endif