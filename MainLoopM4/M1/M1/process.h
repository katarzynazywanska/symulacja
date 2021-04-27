#ifndef EVENT_H_
#define EVENT_H_
#include <functional>
#include <vector>
#include <queue>

class WirelessNetwork;

class Process
{
public:
  typedef std::priority_queue<Process*, std::vector<Process*>, std::function<bool(Process*, Process*)>> Agenda;

  enum class State { GENERATE_PACKET, SEND_PACKET, END_TRANSMISION };
  Process(size_t time, WirelessNetwork* wirless_network, Agenda* agenda);
  virtual ~Process();

  virtual void Execute() = 0;

  size_t get_time() { return time_; }
  void Activate(size_t time, bool relative=true); // relative false sets the direct time, true increments current process time
  bool IsTerminated();
  void SetTerminated();
protected:
  State state_ = State::GENERATE_PACKET;
  size_t time_;
  bool terminated_ = false;
  WirelessNetwork* wirless_network_ = nullptr;
  Agenda* agenda_ = nullptr;

};

#endif

