#ifndef _node_h_
#define _node_h_
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "defines.h"

class Node {
private:
	string name;
	EN_nodeState_t state;
public:
	Node();
	Node(string nameI, EN_nodeState_t stateI = LOW);
	string getName();
	void setName(string nameI);
	EN_nodeState_t getState();
	void setState(EN_nodeState_t valueI);
	
	friend ostream& operator << (ostream& out, const Node& node);
};

#endif