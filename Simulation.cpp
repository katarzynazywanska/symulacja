#include "Simulation.h"

Simulation::Simulation(Network* network): network_(network){
}

void Simulation::start_simulation(int time) {
    clock_ = 0;
    network_->Init();
    std::cout << "Started Simulation method M4: \n";


    auto cmp = [](Process* left, Process* right)
    {
        return left->get_time() > right->get_time();
    };

    Process::Agenda agenda(cmp);

    // Create first User process
    int id = 0;
    auto user = new User(id,clock_,network_,&agenda);
    id++;

    auto bs = new BaseStation(id,clock_,network_,&agenda);
    user->Activate(0); // activate now
    bs->Activate(1);


    std::cout<<"Wybierz tryb symulacji: "<<std::endl;
    std::cout<<"krokowy - 0 "<<std::endl;
    std::cout<<"ciągły - 1 "<<std::endl;
    int flag;
    std::cin>>flag;
    // main loop
    while (clock_ < ( static_cast<int>(time) ))
    {
        if(!flag){
            cin.get();
        }
        Process* process = agenda.top();
        agenda.pop();
        clock_ = network_->current_time;//process->get_time();

        std::cout << "Simulation Time:" << clock_ << "\n";
        process->Execute();

        if (process->IsTerminated())
        {
            delete process;
        }

    }
}