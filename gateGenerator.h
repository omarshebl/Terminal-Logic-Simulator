#ifndef _gateGenerator_h_
#define _gateGenerator_h_
#include "simulator.h"

class GateGenerator {
private:
	Simulator *S;
public:
	GateGenerator(Simulator *Sin);
	void parseInput(ifstream& file);
	Node* createNode(string name);
	Gate* createGate();
	
	bool isGate(string gateType);
	EN_gateType_t getGateType(string gateType);
	EN_nodeState_t getStateType(string stateType);
	EN_actionType_t getActionType(string actionType);
		
};

#endif