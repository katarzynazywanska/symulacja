#include "process.h"

Process::Process(size_t time, WirelessNetwork* wirless_network, Agenda* agenda) : time_(time), wirless_network_(wirless_network), agenda_(agenda)
  
{
}

Process::~Process()
{

}

void Process::Activate(size_t time, bool relative)
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
