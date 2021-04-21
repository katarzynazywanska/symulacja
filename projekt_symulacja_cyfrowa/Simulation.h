#pragma once
#include "User.h"
class Simulation
{
public:
	Simulation(Network* network);
	void start_simulation(int time);
private:
	Network* network_ = nullptr;
	int clock = 0;
	int generate_max_time = 10;
	int sending_data_max_time = 25;
};

