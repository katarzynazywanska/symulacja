#include "BaseStation.h"
#include "Network.h"

BaseStation::BaseStation(int station_ID, int time,Network * network,Agenda *agenda) : Process(time,network,agenda), id_(station_ID) {
    for (int i = 0; i < RESOURCE_BLOCK; i++) {
        ResourceBlock res_block = ResourceBlock();
        bs_res_block_vec_.push_back(res_block);
    }
}

void BaseStation::Execute(){
    bool active = true;
    while (active)
    {
        switch (state_)
        {

            case State::ALLOCATE_RESOURCES:
                if (!bs_res_block_vec_.empty())
                {
                    std::vector<ResourceBlock> copy;
                    copy.push_back(bs_res_block_vec_.front());
                    bs_res_block_vec_.erase(bs_res_block_vec_.begin());
                    network_->get_buffer_first()->set_users_res_block_vec(copy); // przydzielamy resourceblock user'owi
                }

                {
                    int new_id = id_ + 1;
                    BaseStation* new_resource_allocation = new BaseStation(new_id, network_->get_current_time(), network_, agenda_);
                    new_resource_allocation->Activate(network_->single_transmission_time);
                }

                if (!network_->get_buffer_first()->get_users_res_block_vec().empty())
                {
                    state_ = State::SEND_PACKET;
                }
                break;


            case State::SEND_PACKET:

                network_->StartTransmission();
                network_->get_buffer_first()->Activate(network_->single_transmission_time+time_,false);
                network_->set_current_time(network_->get_buffer_first()->get_time());

                state_ = State::DATA_CHECK;
                break;

            case State::DATA_CHECK:
                network_->DataCheck();
                if (!network_->IsBufferEmpty())
                {
                    // wake up next process/packet in buffer in current time
                    network_->get_buffer_first()->Activate(time_, false);
                }

                active = false;
                terminated_ = true;
                break;

        }
    }
}