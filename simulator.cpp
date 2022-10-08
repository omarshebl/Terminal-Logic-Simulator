#include "simulator.h"

Simulator::Simulator() {}

void Simulator::postNode(Node *nPtr) {
	Nodes[nodesNum++] = nPtr;
}

void Simulator::postGate(Gate *gPtr) {
	Gates[gatesNum++] = gPtr;
}

Node* Simulator::findNode(string name) {
	for (int i=0; i<nodesNum; i++) {
		if (name == Nodes[i]->getName()) return Nodes[i];
	}
	return nullptr;
}

int Simulator::getNodesNum() {
	return nodesNum;
}

Node** Simulator::getNodes() {
	return Nodes;
}

void Simulator::startSimulate() {
	for(int i=0; i<gatesNum; i++) Gates[i]->simulateGate();
}

Simulator::~Simulator() {
	for(int i=0; i<nodesNum; i++) delete Nodes[i];
	for(int i=0; i<gatesNum; i++) delete Gates[i];
}