#pragma once
#include <iostream>
#include <queue>
#include "BaseStation.h"
#include "Process.h"


class Network
{
private: 
	BaseStation* BaseStation_;
	bool channel_ = false;
	
public:
	static const int generate_max_time = 10;
	static const int sending_data_time = 25;

	bool IsFree() { return !channel_; }
	bool IsBufferEmpty() { return UserQueue_.empty(); }
	void Init();
	std::queue<Process*> UserQueue_;

	void StartTransmission();
	void EndTransmission();
};

