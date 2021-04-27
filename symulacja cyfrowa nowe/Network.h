#pragma once
#include "User.h"

class Network
{
private:
	BaseStation* base_station_;
	int current_time = 0;

public:
	Network();
	std::vector<User*> user_vector_;
	void Start_transmission();
	void End_transmission();
	void set_current_time(int time) { this -> current_time = time; };
	int get_current_time() { return current_time; };
	BaseStation* get_bs_station_ptr() { return this->base_station_; };
};

