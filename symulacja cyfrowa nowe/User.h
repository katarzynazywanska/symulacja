#pragma once
#include <vector>
#include <string>
#include "BaseStation.h"


class User : public Process
{
private:
	int user_id_;
	int user_apperance_time_;
	int bit_rate_;
	int users_data_;
	std::vector<ResourceBlock> user_res_block_vec_;
	std::string state_ = "Send data";


public:
	void Execute() override;
	User(int id, int user_apperance_time, Network* network);
	
	Network* network_;
	int get_user_id() { return user_id_; };
	int get_user_data() { return users_data_; };
	void set_user_data(int actualization_of_data) {this->users_data_ = actualization_of_data; };
	std::vector<ResourceBlock> get_users_res_block_vec() { return user_res_block_vec_; };
	void set_users_res_block_vec(std::vector<ResourceBlock> new_res_block_vec) { this->user_res_block_vec_ = new_res_block_vec; };
	std::string get_user_state() { return state_; };
	void actualization_of_users_data();
	
	int get_user_app_time() { return user_apperance_time_; };

	bool operator<(const User& user) const {
		return  this->user_apperance_time_ < user.user_apperance_time_;
	}
};

