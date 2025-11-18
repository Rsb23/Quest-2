#ifndef WARDEN_H
#define WARDEN_H

#include "gate.h"

class Warden : public Gate
{
private:
    bool isTruthful{false};

public:
    // getters & setters
    bool getIsTruthful();
    void setIsTruthful(bool inputIsTruthful);

    void assignTruthfulness();
};

#endif