#include "Simulator.h"
#include <stdio.h>
#include <time.h>
#include <random>
#include <iostream>
using namespace std;
#define LAMBDA 1.5

int x;

Simulator::Simulator(Network* network) {
	network_ = network;
}


// main loop 
void Simulator::Start_simulation(int time) {
	std::cout << "Started Simulation method M4: \n";
	Generate_user_vector(time);
	while (network_->get_current_time() <= time) {
		// step mode
		// std::cin.get();
		if (!network_->user_vector_.empty()) {
			network_->get_bs_station_ptr()->Execute();
			network_->user_vector_.front()->Execute();
		}

	}
}

void Simulator::Generate_user_vector(int simulation_time) {
	//srand(time(NULL));
	int amount_of_users = rand() % (simulation_time/2) + simulation_time/3;
	default_random_engine generator;
	exponential_distribution<double> distribution(LAMBDA);

	User* first_user = new User(0, 0, network_);
	network_->user_vector_.push_back(first_user);

	int user_apperance_time;
	for (int i = 0; i < amount_of_users; ++i)
	{
		double number = distribution(generator);
		if (number <= 1.0) {
			user_apperance_time = number * simulation_time;
			User* new_user = new User(i+1, user_apperance_time, network_);
			network_->user_vector_.push_back(new_user);
		}
	}
	std::sort(network_->user_vector_.begin(), network_->user_vector_.end(),UserCompare());
}