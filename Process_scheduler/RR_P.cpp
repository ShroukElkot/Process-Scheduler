#include "RR_P.h"
#include "Controller.h"
#include "operation.h"

//RR_P::RR_P(controller* pCont) :operation(pCont)
//{}


RR_P::RR_P() {
	RDY = new LinkedList<Process>();
	busy = false;
	timeslice = 0;
}
void RR_P::add_to_RDYlist(Process* new_process)
{
	RDY->INSERT(new_process);
}

RR_P ::RR_P(std::string name) : ProcessorName(name) {
	RDY = new LinkedList<Process>();
	busy = false;
	timeslice = 0;
}


void RR_P ::ScheduleAlgo()
{
	int count = RDY->countall();
	for (int i = 0; i < count; i++)

	{
		int currentTime = 0;
		while (currentTime < timeslice)
		{
			set_Run(RDY->getfirst_index(i));
			currentTime++;

		}

	}
}


int RR_P::calc_total_CPUT()
{
	//Process p;
	int totalcputime = 0;
	int count = RDY->countall();
	for (int i = 0; i < count; i++)
	{
		totalcputime = totalcputime + RDY->getatindex2(i)->getCT();
	}

	return totalcputime;
}


void RR_P::setState(bool state)
{
	this->busy = state;
}
bool RR_P::getState()
{
	return this->busy;
}
//template <typename T>
//RR_P<T> ::RR_P(LinkedList<T>* RDY, bool state, int timeslice)
//{
//
//	this->RDY = RDY;
//	this->state = state;
//	this->timeslice = timeslice;
//
//}

LinkedList <Process>* RR_P::getRRreadylist()
{
	return RDY;
}

std::string RR_P ::  get_P_name() const {
	return this->ProcessorName;
}


RR_P::~RR_P() {
	delete RDY;
}
