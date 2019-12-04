
#ifndef SIMULATOR

#define SIMULATOR

#include "gate.h"
#include "vector"

using namespace std;

class Simulator
{
	vector <Gate *> GateArr;
	vector <Node *> NodeArr;
	
public:
	Simulator(void);
	~Simulator(void);
	int GetGateSize();
	Node * findNode(string name);
	Node * AddNode(string name);
	Node * findOrAdd(string name);
	Gate * AddGate (string gateType);
	void Simulate();
	void Load(const char * filePath);
	void printAllNodes();
};

#endif