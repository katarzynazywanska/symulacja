#pragma once
#include "Network.h"

class Simulator
{
	Network* network_;
	int clock;

public:
	void Start_simulation(int time);
	Simulator(Network* network);
	void Generate_user_vector(int simulation_time);
	void set_simulation_time(int new_time) {  this->clock=new_time; };

	
	struct UserCompare {
		bool operator()(const User* user1, const User* user2) {
			return *user1 < *user2;
		}
	};
	
};

