#include "Simulator.h"
#include "iostream"

using namespace std;

int main (int argc ,char *argv []) {
	Simulator S;

	if(argc > 2)
		S.Load(argv[1]);
	else
		cout<<"you didn't enter a file path"<<endl;
	int a;
	cout<<"Enter any key to close"<<endl;
	cin>>a;

	return 0;
}