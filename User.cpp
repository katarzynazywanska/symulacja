#include "User.h"
#include "Network.h"

User::User(int id, int time,Network * network,Agenda *agenda) : Process(time,network,agenda), user_ID_(id) {
    users_data_ = (rand() % 10 + 1) * 250;
    bit_rate_ = (rand() % 781 + 20); //[kbit/s];
}


void User::Execute()
{
    bool active = true;
    while (active)
    {
        switch (state_)
        {
            case State::GENERATE_USER:
                network_->GenerateUser(this);
                {auto new_id = user_ID_ + 1;
                auto new_user = new User(new_id, network_->get_current_time(), network_, agenda_);
                new_user->Activate(rand()%network_->generate_max_time);
                }
             active =false;
             break;
            case State::END_TRANSMISION:
                active =false;
                terminated_=true;
                break;
            case State::SEND_PACKET:
                active=false;
                break;
        }
    }
}


void User::actualization_of_users_data() {
    int temp = bit_rate_ * network_->single_transmission_time;
    users_data_ -= temp;
    if (this->users_data_ < 0) {
        this->users_data_ = 0;
    }
}
