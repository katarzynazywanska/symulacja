#pragma once
#include <iostream>
#include <vector>
#include "ResourceBlock.h"

using namespace std;

class BaseStation
{
private:
	vector<ResourceBlock*> resource_Block_vec; //bloki zasob�w
	bool error; //Prawdopodobie�stwo wyst�pienia b��du transmisji 0.1
	const int s = 5; //Czas po jakim stacja bazowa przydziela zasoby 

public:
	vector<ResourceBlock*> create_resBlocks(int how_many);
};


