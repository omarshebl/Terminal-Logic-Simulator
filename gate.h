#ifndef _gate_h_
#define _gate_h_
#include "node.h"

class Gate {
private:
	int nodesINum = 0;
	EN_gateType_t gateType;
	Node *nodesI[MAX_GATE_INPUTS];
	Node *nodeO;
	
protected:
	void setNodesINum(int in);

public:
	Gate();
	Gate(Node *IN[], int INNum, Node *OUT, EN_gateType_t gateTypeI);
	void simulateGate();
	
	int getNodesINum();
	
	void setGateType(EN_gateType_t in);
	EN_gateType_t getGateType();
	EN_nodeState_t convertIntToState(int in);
	
	void setNodesI(Node *in[], int inNum);
	Node** getNodesI();
	
	void setNodeO(Node *in);
	Node* getNodeO();
	
	
};

#endif