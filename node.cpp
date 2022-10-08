#include "node.h"

Node::Node() {};

Node::Node(string nameI, EN_nodeState_t stateI) {
	name = nameI;
	state = stateI;
}

string Node::getName() { return name; }

void Node::setName(string nameI) { name = nameI; }

EN_nodeState_t Node::getState() { return state; }

void Node::setState(EN_nodeState_t stateI) { state = stateI; }

ostream& operator << (ostream& out, const Node &node) {
	out << string(node.name) << ": " << to_string(node.state);
	return out;
}