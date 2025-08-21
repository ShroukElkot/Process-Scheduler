



#pragma once

#include "Definitions.h"
#include "UI.h"
#include "operation.h"
class operation; //forward declaration

//Main class that manages everything in the application.
class controller
{
	UI *pUI;		//Pointer to UI class

public:
	controller();
	~controller()= default;

	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	//Processor_type GetUseroperation() const;
	operation* createOperation(Processor_type); //Creates an operation
	void Run();

	// -- Interface Management Functions
	UI* GetUI() const; //Return pointer to the UI
	

};

