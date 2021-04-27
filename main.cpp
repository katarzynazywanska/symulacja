#include <iostream>
#include "Simulation.h"
using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    Network* network = new Network();
    Simulation simulation = Simulation(network);

    simulation.start_simulation(200);
}