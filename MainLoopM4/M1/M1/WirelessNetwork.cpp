#include "WirelessNetwork.h"
#include  "Packet.h"
#include <iostream>

void WirelessNetwork::Init()
{
  while (!buffer_.empty())
  {
    delete buffer_.front();
    buffer_.pop();
  }
  channel_ = false;
}

void WirelessNetwork::GeneratePacket(Packet* packet)
{
  buffer_.push(packet);
  std::cout << "Generated Packet id:" << packet->get_id() << "\n";
}

void WirelessNetwork::StartTransmission()
{
  channel_ = true;
  std::cout << "Started transmission of packet:" << buffer_.front()->get_id() << "\n";
}

void WirelessNetwork::EndTransmission()
{
  channel_ = false;
  std::cout << "Ended transmission of packet:" << buffer_.front()->get_id() << "\n";
  buffer_.pop();
  
}
