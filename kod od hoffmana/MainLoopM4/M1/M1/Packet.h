#ifndef  PACKET_H_
#define PACKET_H_
#include "process.h"

class Packet : public Process
{
public:
  Packet(size_t id, size_t time, WirelessNetwork* wireless_network, Agenda* agenda);

  void Execute() override;

  size_t get_id() const { return id_; }
private:
  const size_t id_ = 0;
};

#endif
