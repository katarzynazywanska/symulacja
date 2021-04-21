#include "Network.h"
#include "User.h"

void Network::Init()
{
    while (!UserQueue_.empty())
    {
        delete UserQueue_.front();
        UserQueue_.pop();
    }
    channel_ = false;
}

void Network::StartTransmission()
{
    channel_ = true;
    std::cout << "Started transmission of users data :" << UserQueue_.front()->get_process_ID() << "\n";
}

void Network::EndTransmission()
{
    channel_ = false;
    std::cout << "Ended transmission of of users data:" << UserQueue_.front()->get_process_ID() << "\n";
    UserQueue_.pop();

}