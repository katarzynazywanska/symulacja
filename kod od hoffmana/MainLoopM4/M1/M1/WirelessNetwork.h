#ifndef WIRELESS_NETWORK_H_
#define WIRELESS_NETWORK_H_

#include <queue>

class Packet;

class WirelessNetwork
{
public:
  static const size_t generate_packet_max_time = 10;
  static const size_t transmission_max_time = 25;
  void Init();

  void GeneratePacket(Packet* packet);
  void StartTransmission();
  void EndTransmission();

  bool IsFree() { return !channel_; }
  bool IsBufferEmpty() { return buffer_.empty(); }
  Packet* get_buffer_first() { return buffer_.front(); }

  size_t get_buffer_size() { return buffer_.size(); }


private:
  std::queue<Packet*> buffer_;
  bool channel_ = false; // false -> free true -> busy 


};

#endif


