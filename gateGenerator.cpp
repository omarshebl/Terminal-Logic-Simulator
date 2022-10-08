#include "gateGenerator.h"

GateGenerator::GateGenerator(Simulator *Sin) {
	S = Sin;
}

void GateGenerator::parseInput(ifstream& file) {
	string input;
	string word;
	EN_gateType_t gateType;
	EN_actionType_t actionType;
	
	while (getline(file, input)) {
		if (file.eof()) break;
		istringstream ss(input);	
		ss >> word;
		if (isGate(word)) {
			gateType = getGateType(word);
			string nodesS[MAX_GATE_INPUTS];
			int nodesINum = 0;
			
			while (ss >> word) {nodesS[nodesINum++] = word;}
			
			Node *NodesIToSend[nodesINum-1];
			Node *re;
			
			// Looping through input nodes.
			
			for (int i=0; i<nodesINum-1; i++) {
				if(S->findNode(nodesS[i]) == nullptr) {
					re = new Node;
					re->setName(nodesS[i]);
					S->postNode(re);
				} else re = S->findNode(nodesS[i]);
				NodesIToSend[i] = re;
			}
			
			// Output node.
			if(S->findNode(nodesS[nodesINum-1]) == nullptr) {
				re = new Node;
				re->setName(nodesS[nodesINum-1]);
				S->postNode(re);
			} else re = S->findNode(nodesS[nodesINum-1]);
			
			Gate* gre = new Gate;
			
			gre->setGateType(gateType);
			gre->setNodeO(re);
			gre->setNodesI(NodesIToSend, nodesINum-1);
			
			S->postGate(gre);
		} else {
			string node, state;
			Node *nodePtr;
			switch (getActionType(word)) {
				case SET:
					ss >> node >> state;
					nodePtr = S->findNode(node);
					nodePtr->setState(getStateType(state));
					break;
				case OUT:
					ss >> node;
					if (node != "ALL") {
						nodePtr = S->findNode(node);
						cout << *nodePtr << endl;
					} else if (node == "ALL")
						for (int i=0; i<S->getNodesNum(); i++) {
							Node **Nodes = S->getNodes();
							cout << *Nodes[i] << endl;
						}
					break;
				case SIM:
					S->startSimulate();
					break;
			}
		}
		
		
	}
}

Node* GateGenerator::createNode(string name) {
	Node *re = new Node;
	re->setName(name);
	return re;
}

Gate* GateGenerator::createGate() {
	Gate *re = new Gate;
	// set gate
	return re;
}

bool GateGenerator::isGate(string gateType) {
	bool result = false;
	
	if (gateType == "AND") result = true;
	else if (gateType == "NAND") result = true;
	else if (gateType == "OR") result = true;
	else if (gateType == "NOR") result = true;
	else if (gateType == "XOR") result = true;
	else if (gateType == "XNOR") result = true;
	else if (gateType == "NOT") result = true;
	
	return result;
}


EN_gateType_t GateGenerator::getGateType(string gateType) {
	EN_gateType_t type;
	
	if (gateType == "AND") type = AND;
	else if (gateType == "NAND") type = NAND;
	else if (gateType == "OR") type = OR;
	else if (gateType == "NOR") type = NOR;
	else if (gateType == "XOR") type = XOR;
	else if (gateType == "XNOR") type = XNOR;
	else if (gateType == "NOT") type = NOT;
	
	return type;
}

EN_nodeState_t GateGenerator::getStateType(string stateType){
	EN_nodeState_t type = LOW;
	
	if (stateType == "1") type = HIGH;
	
	return type;
}

EN_actionType_t GateGenerator::getActionType(string actionType) {
	EN_actionType_t type;
	if (actionType == "SET") type = SET;
	else if (actionType == "OUT") type = OUT;
	else if (actionType == "SIM") type = SIM;
	return type;
}