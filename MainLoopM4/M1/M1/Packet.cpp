#include "Packet.h"
#include  "WirelessNetwork.h"


Packet::Packet(size_t id, size_t time, WirelessNetwork* wireless_network, Agenda* agenda) : Process(time, wireless_network, agenda), id_(id)
{
}

void Packet::Execute()
{
  bool active = true;
  while (active)
  {
    switch (state_)
    {
    case State::GENERATE_PACKET:

      wirless_network_->GeneratePacket(this);

      { auto new_id = id_ + 1;
        auto new_packet = new Packet(new_id, time_, wirless_network_, agenda_);
        new_packet->Activate(rand() % WirelessNetwork::generate_packet_max_time);
      }
      // if channel free proceed immediately to transmission phase, otherwise change state but dis-activate
      // process
      if (wirless_network_->IsFree())
      {
        state_ = State::SEND_PACKET;
      }
      else
      {
        state_ = State::SEND_PACKET;
        active = false;
      }

      break;

    case State::SEND_PACKET:

      wirless_network_->StartTransmission();
      Activate(rand() % WirelessNetwork::transmission_max_time);
      state_ = State::END_TRANSMISION;
      active = false;

      break;
    case State::END_TRANSMISION:

      wirless_network_->EndTransmission();

      if (!wirless_network_->IsBufferEmpty())
      {
        // wake up next process/packet in buffer in current time
        wirless_network_->get_buffer_first()->Activate(time_, false);
      }
      
      active = false;
      terminated_ = true;
      break;
    }
  }
}
