#pragma once
#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "Process.h"
#include "Definitions.h"
#include <string>
//#include "operation.h"
using namespace std;
//template <typename T>
class Processor
{
private:
	Process* Run;
	Processor_type type;
	bool busy;  // state 
	
public:
	Processor();
	void set_Run(Process* R);
	Process* get_Run();
	Processor_type getType();
	void setProcessor_type(Processor_type ty);
	virtual void add_to_RDYlist(Process* new_process) = 0;
	virtual void setState(bool state) = 0;
	virtual bool getState() = 0;
	//virtual T get_RDYlist()=0;
	virtual void ScheduleAlgo() = 0;
	~Processor();
};


#endif // 
