

#include "Simulator.h"
#include  "WirelessNetwork.h"
#include <memory>

int main(int argc, char* argv[])
{
  WirelessNetwork* wireless_network = new WirelessNetwork();
  Simulator simulator = Simulator(wireless_network);

  simulator.Run(200);


}
