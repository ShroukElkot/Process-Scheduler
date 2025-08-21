#ifndef SJF_P_CPP
#define SJF_P_CPP
#include <iostream>
using namespace std;

#include "SJF_P.h"
#include "Priority_queue.h"
#include "Priority_queue.cpp"
#include "Scheduler.h"
#include "Controller.h"
#include "operation.h"
using namespace std;
#include <string>
#include <iostream>


SJF_P ::SJF_P()
{
	RDY = new Priority_queue<Process>();
	busy = false;
}

SJF_P::SJF_P(std::string name) : ProcessorName(name) {
	RDY = new Priority_queue<Process>();
	busy = false;
}
//SJF_P::SJF_P(controller* pCont) :operation(pCont)
//{}



//SJF_P ::SJF_P(Process* P, double priority)
//{
//	RDY->Enqueue(P,priority);
//}


void SJF_P ::setState(bool state)
{
	this->busy = state;
}

bool SJF_P ::getState()
{
	return this->busy;
}

//void SJF_P::add_to_RDYlist(Process* new_process)
//{
//	//RDY->Enqueue(new_process,new_process->getCT());
//}

void SJF_P::add_to_RDYlist(Process* new_process)
{
	//Node <Process>* node = new Node<Process>;
	//auto node = new_process;
	
	//node->setItem(new_process->get_Id());
	//RDY->Enqueue(std::pair<Process*, double>(new_process, new_process->getCT()));

	//RDY->Enqueue(new_process->get_Id(), new_process->getCT());
	//RDY->Enqueue(std::make_pair(new_process, new_process->getCT()), new_process->getCT());
	RDY->Enqueue(new_process, new_process->getCT());
}

void SJF_P:: ScheduleAlgo() // gets the process with smallest CT time (least priority (Tail of the priority Q))
{
	//RDY->getTail();
	if (RDY->IsEmpty())
	{
		return;
	}

	else 
	{
		while (RDY->IsEmpty() == false);
		//while (RDY.IsEmpty()==false)
		{
			if (get_Run() == nullptr)
			{
				//Node <T>* temp = RDY.Dequeue();
				
				auto Run_node = RDY->Dequeue();

				auto Run_Process = Run_node->first;
				set_Run(Run_Process);
				setState(true);
				 // need to implement a function in priority Q that takes a node as a parameter and delete it
			}
			else // if run != null means the processor is runing a process
			{
			
				return;
				
			}
		}
	}
	

}

Priority_queue<Process>* SJF_P::getSJFreadylist()
{
	return RDY;
}


std::string SJF_P::get_P_name() const {
	return this->ProcessorName;
}

SJF_P::~SJF_P() {
	delete RDY;
}

#endif // !SJF_P_CPP




