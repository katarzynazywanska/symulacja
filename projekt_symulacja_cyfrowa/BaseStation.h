#pragma once
#include <iostream>
#include <vector>
#include "ResourceBlock.h"

using namespace std;

class BaseStation
{
private:
	vector<ResourceBlock*> resource_Block_vec; //bloki zasobów
	bool error; //Prawdopodobieñstwo wyst¹pienia b³êdu transmisji 0.1
	const int s = 5; //Czas po jakim stacja bazowa przydziela zasoby 

public:
	vector<ResourceBlock*> create_resBlocks(int how_many);
};


