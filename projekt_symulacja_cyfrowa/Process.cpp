#include "Process.h"
#include "Network.h"
Process::Process() {
};

Process::Process(double time, Network* network) : time_(time), network_(network){
}

Process::~Process()
{

}


void Process::Activate(double time, bool relative)
{
    if (relative)
    {
        time_ += time;
    }
    else
    {
        time_ = time;
    }

    network_->UserQueue_.push(this);
}

bool Process::IsTerminated()
{
    return terminated_;
}

void Process::SetTerminated()
{
    terminated_ = true;
}