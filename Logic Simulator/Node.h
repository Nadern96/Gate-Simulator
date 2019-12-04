#ifndef NODE_H

#define NODE_H
#include <string>
using namespace std;

class Node 
{
	string Name;
	short Value;

public:
	Node();
	Node (string name);
	Node (string name, short val);
	void SetName(string name);
	string GetName();
	void SetValue(short val);
	short GetValue();
	void printNode();
};

#endif