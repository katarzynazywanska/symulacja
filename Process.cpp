#include "Process.h"
#include "Network.h"


Process::Process(int time, Network* network, Agenda *agenda) : time_(time), network_(network),agenda_(agenda){
}

Process::~Process()
{

}

void Process::Activate(int time, bool relative)
{
    if (relative)
    {
        time_ += time;
    }
    else
    {
        time_ = time;
    }

    agenda_->push(this);
}

bool Process::IsTerminated()
{
    return terminated_;
}

void Process::SetTerminated()
{
    terminated_ = true;
}