#pragma once
#ifndef OPERATION_H
#define OPERATION_H


#pragma once
#include "Definitions.h"
#include "UI.h"
class Controller; //forward class declaration


//Base class for all possible operations
class operation
{
protected:
	Controller* pControl;	//operations needs control to do their job


public:
	//operation();
	//operation(Controller* pCont) { pControl = pCont; }	//constructor
	virtual ~operation(){}



};



#endif // !