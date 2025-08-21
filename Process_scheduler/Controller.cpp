#include "Controller.h"
#include "Definitions.h"
#include "FCFS_P.h"
#include "Processor.h"
#include "SJF_P.h"
#include "RR_P.h"

//Constructor
controller::controller()
{
	pUI = new UI;	//Create GUI object

}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
//Processor_type controller::GetUseroperation() const
//{
//	//Ask the input to get the operation from the user.
//	return;// pUI->GetUseroperation();
//}

operation* controller::createOperation(Processor_type OpType)
{
	operation* pOp = nullptr;

	//According to operation Type, create the corresponding operation object
	//switch (OpType)
	//{
	//case FCFS:
	//	pOp = new FCFS_P();
	//	break;
	//case SJF:
	//	pOp = new SJF_P();
	//	break;
	//case RR:
	//	pOp = new RR_P();
	//	break;


	//}

	return pOp;

}