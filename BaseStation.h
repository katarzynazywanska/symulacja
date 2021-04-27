#pragma once
#include <iostream>
#include <vector>
#include "ResourceBlock.h"
#include "Process.h"
#define RESOURCE_BLOCK 1

using namespace std;

class BaseStation: public Process
{
private:

    vector<ResourceBlock*> resource_Block_vec; //bloki zasobOw

    std::vector<ResourceBlock> bs_res_block_vec_;
    int time;
    bool error; //Prawdopodobie�stwo wyst�pienia b��du transmisji 0.1
    const int s = 5; //Czas po jakim stacja bazowa przydziela zasoby
    const int id_=0;
public:
    int get_id() const {return id_;}
    void Execute() override;
    BaseStation(int id, int time, Network* network, Agenda* agenda);
    vector<ResourceBlock*> create_resBlocks(int how_many);
    State state_ = State::ALLOCATE_RESOURCES;
};

