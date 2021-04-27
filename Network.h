#pragma once
#include <iostream>
#include <queue>
#include "User.h"

class Network
{


public:
    static const int generate_max_time = 5;
    int single_transmission_time = 5;
    int current_time=1;
    void Init();
    void GenerateUser(User* user);
    void StartTransmission();
    void DataCheck();

    bool IsBufferEmpty() { return buffer_.empty(); }
    User* get_buffer_first() { return buffer_.front(); }

    size_t get_buffer_size() { return buffer_.size(); }
    std::queue<User*> buffer_;

    int get_current_time(){return current_time;}
    void set_current_time(int new_time){this->current_time=new_time;}


};
