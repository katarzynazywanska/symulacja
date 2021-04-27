#include "GeneratePacketEvent.h"
#include "network.h"

GeneratePacketEvent::GeneratePacketEvent(size_t time, Network* network) : Event(time), network_(network)
{
	
}

void GeneratePacketEvent::Execute()
{
	network_->GeneratePacket();

	// Schedule next GeneratePacketEvent
}
