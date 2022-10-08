#include "gate.h"

Gate::Gate() {};

Gate::Gate(Node *IN[], int INNum, Node *OUT, EN_gateType_t gateTypeI) {
	setNodesI(IN, INNum);
	setNodeO(OUT);
	setGateType(gateTypeI);
}

void Gate::simulateGate() {
	int result;
	bool NOTenter = false;
	switch (gateType) {
		case NAND:
			NOTenter = true;
		case AND:
			result = 1;
			for(int i=0; i<nodesINum; i++) result *= nodesI[i]->getState();
			if (NOTenter) result = (result>0)?0:1;
			break;
		case NOR:
			NOTenter = true;
		case OR:
			result = 0;
			for(int i=0; i<nodesINum; i++) result += nodesI[i]->getState();
			result = (result>0)?1:0;
			if (NOTenter) result = (result>0)?0:1;
			break;
		case XNOR:
			NOTenter = true;
		case XOR:
			result = nodesI[0]->getState();
			for(int i=1; i<nodesINum; i++) result ^= nodesI[i]->getState();
			if (NOTenter)  result = (result>0)?0:1;
			break;
		case NOT:
			result = nodesI[0]->getState();
			result = (result>0)?0:1;
			break;
	}
	nodeO->setState(convertIntToState(result));
}

void Gate::setNodesINum(int in) {
	nodesINum = in;
}

int Gate::getNodesINum() {
	return nodesINum;
}

void Gate::setGateType(EN_gateType_t in) {
	gateType = in;
}

EN_gateType_t Gate::getGateType() {
	return gateType;
}

EN_nodeState_t Gate::convertIntToState(int in) {
	EN_nodeState_t result = LOW;
	if(in > 0) result = HIGH;
	return result;
}


void Gate::setNodesI(Node *in[], int inNum) {
	for (int i=0; i<inNum; i++) nodesI[nodesINum++] = in[i];
}

Node** Gate::getNodesI() {
	return nodesI;
}

void Gate::setNodeO(Node *in) {
	nodeO = in;
}

Node* Gate::getNodeO() {
	return nodeO;
}