
#include "Simulator.h"
#include <memory>
#include <time.h>

int main(int argc, char* argv[])
{
	srand(time(NULL));
	Network* network = new Network();
	Simulator simulator = Simulator(network);

	simulator.Start_simulation(200);
}
