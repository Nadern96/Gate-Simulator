#include "Node.h"
#include "iostream"

using namespace std;

Node :: Node() 
{
	Name = "";
	Value = 0;
}

Node :: Node(string name) 
{
	Name = name;
	Value = 0;
}

Node :: Node(string name , short val) 
{
	Name = name;
	Value = val;
}

void Node :: SetName(string name)
{
	Name = name;
}

string Node :: GetName ()
{
	return Name;
}

void Node :: SetValue(short val)
{
	Value = val;
}

short Node :: GetValue ()
{
	return Value;
}

void Node :: printNode()
{
	cout<<this->Name<<"-"<<this->Value<<endl;
}
