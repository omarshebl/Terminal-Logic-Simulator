#include "gateGenerator.h"


int main(int argc, char *argv[]) {
	
	Simulator *S = new Simulator;
	GateGenerator G(S);
	ifstream file;
	
	file.open("gates.txt");
	if (file.is_open()) {
		G.parseInput(file);
	}
	file.close();
	
	delete S;
	return 0;
}