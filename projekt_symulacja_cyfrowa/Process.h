#pragma once
#include <iostream>
#include <vector>
#include "vector"
using namespace std;

class Network;

class Process
{
public:

	enum class State { GENERATE_PACKET, SEND_PACKET, END_TRANSMISION };
	//Process(double time, Network* network);
	Process();
	Process(double time, Network* network);
	virtual ~Process();

	virtual void Execute(Network* network) = 0;

	double get_time() { return time_; }
	void Activate(double time, bool relative = true); // relative false sets the direct time, true increments current process time
	bool IsTerminated();
	void SetTerminated();
	int get_process_ID() { return process_ID; };
protected:
	State state_ = State::GENERATE_PACKET;
	double time_;
	bool terminated_ = false;
	Network *network_ = nullptr;
	int process_ID;
};