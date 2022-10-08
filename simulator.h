#ifndef _simulator_h_
#define _simulator_h_
#include "gate.h"

class Simulator {
private:
	Node *Nodes[MAX_NODES];
	Gate *Gates[MAX_GATES];
	int nodesNum = 0;
	int gatesNum = 0;
public:
	Simulator();
	void postNode(Node *nPtr);
	void postGate(Gate *gPtr);
	Node* findNode(string name);
	
	int getNodesNum();
	Node** getNodes();
	void startSimulate();
	~Simulator();
};
#endif