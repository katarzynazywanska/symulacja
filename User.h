
#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "BaseStation.h"
using namespace std;


class User : public Process
{
private:
    int users_data_; //ilosc danych jakie mozna odebrac
    int user_ID_=0;
    int bit_rate_;
    std::vector<ResourceBlock> user_res_block_vec_;
public:
    State state_ = State::GENERATE_USER;
    User(int user_ID, int t,Network * network,Agenda *agenda);
    void Execute() override;
    int get_user_ID() { return user_ID_; };
    int get_users_data(){return users_data_;}
    std::vector<ResourceBlock> get_users_res_block_vec() { return user_res_block_vec_; };
    void set_users_res_block_vec(std::vector<ResourceBlock> new_res_block_vec) { this->user_res_block_vec_ = new_res_block_vec; };
    void actualization_of_users_data();

};