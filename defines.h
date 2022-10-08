#ifndef _defines_h_
#define _defines_h_

#define MAX_GATES 100
#define MAX_NODES 300
#define MAX_GATE_INPUTS 10

enum EN_gateType_t {
	AND, NAND, OR, NOR, XOR, XNOR, NOT
};

enum EN_nodeState_t {
	LOW, HIGH
};

enum EN_actionType_t {
	SET, SIM, OUT
};

#endif