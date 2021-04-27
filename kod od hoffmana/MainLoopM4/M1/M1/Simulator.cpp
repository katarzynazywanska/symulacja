#include "Simulator.h"
#include <iostream>
#include "process.h"
#include "Packet.h"


Simulator::Simulator(WirelessNetwork* wireless_network) : wireless_network_(wireless_network)
{
}



void Simulator::Run(int time)
{
  clock_ = 0;
  wireless_network_->Init();
  std::cout << "Started Simulation method M4: \n";

  auto cmp = [](Process* left, Process* right) 
  { 
      return left->get_time() > right->get_time(); 
  };

  Process::Agenda agenda(cmp);

  // Create first packet process
  size_t id = 0;
  auto packet = new Packet(id, clock_, wireless_network_, &agenda);
  packet->Activate(0); // activate now  

  // main loop
  while (clock_ < static_cast<size_t>(time))
  {
    Process* process = agenda.top();
    agenda.pop();
    clock_ = process->get_time();

    std::cout << "Simulation Time:" << clock_ << "\n";
    process->Execute();

    if (process->IsTerminated())
    {
      delete process;
    }
    
  }
}


