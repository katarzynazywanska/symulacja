#include "Network.h"

void Network::Init()
{
    while (!buffer_.empty())
    {
        delete buffer_.front();
        buffer_.pop();
    }
}

void Network::GenerateUser(User* user)
{
    buffer_.push(user);
    std::cout << "Generated User id:" << user->get_user_ID() << "\n";
}


void Network::StartTransmission()
{
    std::cout << "Started transmission of users data :" << get_buffer_first()->get_user_ID() << "\n";
    get_buffer_first()->actualization_of_users_data();
}

void Network::DataCheck()
{
    std::cout << "Ended transmission of users data:" << get_buffer_first()->get_user_ID() << "\n";
    if (!IsBufferEmpty() && get_buffer_first()->get_users_data()==0){
        get_buffer_first()->state_=Process::State::END_TRANSMISION;
        buffer_.pop();
    }
    else{
        get_buffer_first()->state_=Process::State::SEND_PACKET;
    }

}