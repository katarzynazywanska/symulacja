#include "BaseStation.h"
#include "Network.h"
#include <iostream>

BaseStation::BaseStation(Network* network) : Process(network) {
	for (int i = 0; i < RESOURCE_BLOCK; i++) {
		ResourceBlock res_block = ResourceBlock();
		bs_res_block_vec_.push_back(res_block);
	}
	network_ = network;
}

void BaseStation::Execute() {
	if (network_->user_vector_.front()->get_user_state() == "Send data") {
		Allocate_res_block();
		std::cout << "Allocate res_block to user: " << network_->user_vector_.front()->get_user_id() << " in time : "; 
		std::cout << network_->get_current_time() << "ms, who appear in " << network_->user_vector_.front()->get_user_app_time() << " ms" << std::endl;
	}
	else {
		Take_back_res_block();
	}
}

void BaseStation::Allocate_res_block() {
	std::vector<ResourceBlock> kopia = network_->user_vector_.front()->get_users_res_block_vec();
	kopia.push_back(bs_res_block_vec_.front());
	bs_res_block_vec_.erase(bs_res_block_vec_.begin());
	network_->user_vector_.front()->set_users_res_block_vec(kopia);
}

void BaseStation::Take_back_res_block() {
	for (ResourceBlock &res_block : network_->user_vector_.front()->get_users_res_block_vec())
	{
		bs_res_block_vec_.push_back(res_block);
	}
	network_->user_vector_.front()->get_users_res_block_vec().clear();
}