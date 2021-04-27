#ifndef SIMULATOR_H_
#define SIMULATOR_H
#include "WirelessNetwork.h"

class Simulator
{
public:

  explicit Simulator(WirelessNetwork* wireless_network);
  void Run(int time);

private:
  size_t generate_packet_max_time = 10;
  size_t transmission_max_time = 25;
  size_t clock_ = 0;
  WirelessNetwork* wireless_network_ = nullptr;
};

#endif


