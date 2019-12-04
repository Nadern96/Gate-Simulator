#include "Simulator.h"
#include "AndGate.h"
#include "ORGATE.h"
#include "fstream"

using namespace std;

Simulator::Simulator(void)
{
	
}


Simulator::~Simulator(void)
{
	int i;

	for(i=0 ; i<NodeArr.size() ; i++)
		delete NodeArr[i];

	for(i=0 ; i<GateArr.size() ; i++)
		delete GateArr[i];
}

int Simulator :: GetGateSize()
{
	return GateArr.size();
}

Node* Simulator :: findNode(string name)
{
	int i ;
	for (i=0 ; i<NodeArr.size() ; i++)
	{
		if(NodeArr[i]->GetName() == name)
			return NodeArr[i];
	}
	return NULL;
}

Node * Simulator :: AddNode(string name)
{
	Node *N = new Node (name);
	NodeArr.push_back(N);

	return N;
}

Node * Simulator :: findOrAdd(string name)
{
	Node *N = findNode(name);
	if(N != NULL)
		return N;
	
	return AddNode(name);
}

Gate * Simulator :: AddGate (string gateType)
{
	Gate *p = NULL; 
	if(gateType == "AND")
		p = new ANDGate();
	else if (gateType == "OR")
		p = new ORGate();

	GateArr.push_back(p);

	return p;
}

void Simulator :: Simulate()
{

	for(int j=0 ; j<GateArr.size();j++){ // this loop solves problem that occure when the user enters the gates not in order
		for(int i=0 ; i<GateArr.size() ; i++)
			GateArr[i] -> CalcOut();
	}
}

void Simulator :: Load(const char * filePath)
{
	ifstream file;
	file.open(filePath);
	
	while(!file.eof())
	{
		string s;
		file>>s;

		if(s == "SET")
		{
			string NodeName;
			short val;
			file>>NodeName>>val;
			findOrAdd(NodeName)->SetValue(val);
		}

		else if (s == "OUT"){
			string N ; 
			file>>N;

			if(N == "ALL")
				printAllNodes();
			else
				findOrAdd(N)->printNode();
		}

		else if (s == "SIM")
			Simulate();
		//Gates
		else{
			Gate *gate = AddGate(s);
			string in1 , in2 , out;

			file>>in1>>in2>>out;
			gate->SetIn1(findOrAdd(in1));
			gate->SetIn2(findOrAdd(in2));
			gate->SetOut1(findOrAdd(out));

		}
	}

	file.close();
}

void Simulator :: printAllNodes()
{
	int i;
	for(i =0 ; i < NodeArr.size() ; i++)
	{
		NodeArr[i]->printNode();
	}
}
