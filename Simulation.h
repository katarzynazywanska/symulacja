#pragma once
#include "User.h"
#include "Network.h"
class Simulation
{
public:
    Simulation(Network* network);
    void start_simulation(int time);
private:
    Network* network_ = nullptr;
    int clock_ = 0;
};

