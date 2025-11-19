#ifndef GUARDIAN_H
#define GUARDIAN_H

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

    void encounterGate(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY) override;
    void encounterWarden(std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY) override;
};

#endif