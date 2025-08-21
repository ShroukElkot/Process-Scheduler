#ifndef PROCESSOR_CPP
#define PROCESSOR_CPP

#include "Processor.h"

Processor ::Processor()
{
	this->Run = nullptr;
	this->type = FCFS;
	this->busy = false;
}

Processor :: ~Processor()
{

}

void Processor ::set_Run(Process* R)
{
	this->Run = R;
}

Process* Processor ::get_Run()
{
	return Run;
}


Processor_type Processor ::getType()
{
	return this->type;
}

void Processor :: setProcessor_type(Processor_type ty)
{
	this->type = ty;
}

#endif // !PROCESSOR_CPP