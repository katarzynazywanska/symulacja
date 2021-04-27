#ifndef GENERATE_PACKET_EVENT_H_
#define GENERATE_PACKET_EVENT_H_
#include "Event.h"

class Network;

class GeneratePacketEvent :
	public Event
{

public:
	GeneratePacketEvent(size_t time, Network* network);

	void Execute() override;

private:
	Network* network_ = nullptr;
	// EventList*
};

#endif


