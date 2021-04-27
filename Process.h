#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include "vector"

class Network;

class Process
{
public:
    typedef std::priority_queue<Process*, std::vector<Process*>, std::function<bool(Process*, Process*)>> Agenda;

    enum class State { GENERATE_USER, SEND_PACKET, END_TRANSMISION, ALLOCATE_RESOURCES, DATA_CHECK};
    //Process(double time, Network* network);
  //  Process();
    Process(int time, Network* network, Agenda* agenda);
    virtual ~Process();

    virtual void Execute() = 0;

    double get_time() { return time_; }
    void Activate(int time, bool relative = true); // relative false sets the direct time, true increments current process time
    bool IsTerminated();
    void SetTerminated();
protected:

    int time_;
    bool terminated_ = false;
    Network *network_ = nullptr;
    Agenda* agenda_ = nullptr;
};
