#include "User.h"


User::User(int user_ID, int t, Network* network) {
	users_data = (rand() % 10 + 1) * 250;
	this->user_ID = user_ID;
	this->t = t;
	prop_conditions = (rand() % 781 + 20) * 1000; //[bit/s]
	propagation_conditions.push_back(prop_conditions);
    network->UserQueue_.push(this);
}

double User::sending_data_time() {
    return users_data / prop_conditions;
}

void User::Execute(Network* network)
{
    bool active = true;
    while (active)
    {
        switch (state_)
        {
        case State::GENERATE_PACKET:
       
        {int new_id = user_ID + 1;
        auto new_user = new User(new_id, t, network);
        new_user->Activate(new_user->sending_data_time());
        }
            // if channel free proceed immediately to transmission phase, otherwise change state but dis-activate
            // process
            if (network->IsFree())
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

            network->StartTransmission();
            Activate( sending_data_time() );
            state_ = State::END_TRANSMISION;
            active = false;

            break;
        case State::END_TRANSMISION:

            network->EndTransmission();

            if (!network->IsBufferEmpty())
            {
                // wake up next process/packet in buffer in current time
                network->UserQueue_.front()->Activate(time_, false);
            }

            active = false;
            terminated_ = true;
            break;
        }
    }
}
