#pragma once

class Network;

class Process
{
public: 
	virtual void Execute() = 0;
	Process(Network* network);

private:
	int clock_ = 0;
	Network *network_;
};

