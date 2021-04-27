#pragma once
#include "Process.h"
#include <vector>
#include "ResourceBlock.h"
#define RESOURCE_BLOCK 1


class BaseStation : Process
{
private:
	const int sleep_time_ = 5;
	std::vector<ResourceBlock> bs_res_block_vec_;
	Network* network_;

public:
	BaseStation(Network* network);
	void Execute() override;
	void Allocate_res_block();
	void Take_back_res_block();
	int get_sleep_time_() { return sleep_time_; };
};

