// projekt_symulacja_cyfrowa.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Simulation.h"
using namespace std;

int main(int argc, char* argv[])
{
	Network* network = new Network();
	Simulation simulation = Simulation(network);
	
	simulation.start_simulation(200);
}