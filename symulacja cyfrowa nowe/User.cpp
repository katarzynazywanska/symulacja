#include "User.h"
#include "Network.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

User::User(int id, int user_apperance_time, Network* network) : Process(network) {
	user_id_ = id;
	//srand(time(NULL));
	user_apperance_time_ = user_apperance_time;
	bit_rate_ = (rand() % 781 + 20); //[kbit/s];
	users_data_ = (rand() % 10 + 1) * 250;
	network_ = network;
}

void User::Execute() {
	bool active = true;
	while (active) {
		if (state_ == "Send data") {
			network_->Start_transmission();
			network_->set_current_time(network_->get_current_time() + 5);

			state_ = "End sending data";
		}
		else if (state_ == "End sending data") {
			network_->get_bs_station_ptr()->Execute();
			std::cout << "Start with data: " << users_data_ << " bits  and bit rate : "<< bit_rate_ <<"kbit/s "<< std::endl;
			actualization_of_users_data();
			std::cout << "End with: " << users_data_<<  " bits " << std::endl;
			network_->End_transmission();
			if (network_->user_vector_.front()->user_apperance_time_ > network_->get_current_time()) {
				network_->set_current_time(network_->user_vector_.front()->user_apperance_time_);
			}
			active = false;
		}
	}
}

void User::actualization_of_users_data() {
	 int temp = bit_rate_ * network_->get_bs_station_ptr()->get_sleep_time_();
	 this->users_data_ -= temp;
	 if (this->users_data_ < 0) {
		 this->users_data_ = 0;
	 }
}

