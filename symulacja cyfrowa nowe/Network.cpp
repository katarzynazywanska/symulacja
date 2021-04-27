#include "Network.h"
#include <iostream>
using namespace std;

Network::Network() {
	base_station_ = new BaseStation(this);
	
}

void Network::Start_transmission() {
	std::cout << "Started data transmission of user: " << user_vector_.front()->get_user_id() << endl;
}

void Network::End_transmission() {
	std::cout << "Ended data transmission of user: " << user_vector_.front()->get_user_id() << endl << endl;
	if (user_vector_.front()->get_user_data()) {
		std::rotate(user_vector_.begin(), user_vector_.begin() + 1, user_vector_.end());
	}
	else 
		user_vector_.erase(user_vector_.begin());
}

