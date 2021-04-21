#include "Simulation.h"

Simulation::Simulation(Network* network){
	network = network;
}

void Simulation::start_simulation(int time) {
    double clock_ = 0;
    network_->Init();
    std::cout << "Started Simulation method M4: \n";

    // Create first User process
    int id = 0;
    auto user = new User(id, clock_, network_);
    user->Activate(0); // activate now  
   
    // main loop
    while (clock_ < ( static_cast<int>(time) ))
    {
        
        Process* process = network_->UserQueue_.front();
        network_->UserQueue_.pop();
        clock_ = process->get_time();

        std::cout << "Simulation Time:" << clock_ << "\n";
        process->Execute(network_);

        if (process->IsTerminated())
        {
            delete process;
        }

    }
}