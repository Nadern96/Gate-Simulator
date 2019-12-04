#include "Gate.h"

Gate :: Gate()
{
	In1 = NULL;	
	In2 = NULL;	
	Out1 = NULL;	
}
void Gate :: SetIn1 (Node* in1)
{
	this->In1 = in1;	
}
void Gate :: SetIn2  (Node* in2)
{
	this->In2 = in2;
}
void Gate :: SetOut1 (Node* out1)
{
	this->Out1 = out1;
}
Node* Gate :: GetIn1 ()
{
	return In1;	
}
Node* Gate :: GetIn2 ()
{
	return In2;
}
Node* Gate :: GetOut1 ()
{
	return Out1;
}

	