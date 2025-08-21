#pragma once
#include "Processor.h"
#include "Queue.cpp"
#include "Process.h"
#include "LinkedList.h"
#include <cstdlib>
#include <ctime>
#include "operation.h"
#include <string>
#include <iostream>
using namespace std;

//template <typename T>
class FCFS_P : public Processor //, public operation
{
private:

	LinkedList<Process>* RDY;
	bool busy;
	Queue <Process>* SignKill;
	int currenttime;
	std :: string ProcessorName;


public:

	FCFS_P()
	{
		busy = false;
		RDY = new LinkedList<Process>();
		SignKill = new Queue<Process>();
	}
	FCFS_P(std::string name) : ProcessorName(name) {
		busy = false;
		RDY = new LinkedList<Process>();
		SignKill = new Queue<Process>();
	}


	//FCFS_P(LinkedList<Process>* RDY, bool state, Queue <Process>* SignKill)
	//{
	//	this->RDY = RDY;
	//	this->state = state;
	//	this->SignKill = SignKill;
	//}
	void KillProcess(int pid) {

		while (RDY->getfirst() != nullptr)
		{
			Process p;
			Process* KilledP;
			//Scheduler<Process*> s;
			if (get_Run()->get_Id() == pid)
			{
				KilledP = get_Run();
				//delete KilledP;             
				 //call func move to TRM
				//s.MoveToTRM(KilledP);
				set_Run(nullptr);

			}

			else if (RDY->getatindex2(p.get_Id())->get_Id() == pid) /// do not delete
			{
				KilledP = RDY->getatindex2(p.get_Id());
				//RDY->delete_node(pid);                 
				  // call func move to TRM
				//s.MoveToTRM(KilledP);

			}
		}

	}

	//void manage_process(Process p)
	//{
	//	srand(time(NULL));
	//	int randomNumber = rand() % 100 + 1;
	//	if (randomNumber >= 1 && randomNumber <= 15)
	//		// move the process to BLK list
	//	{

	//		set_Run(nullptr);
	//	}
	//	else if (randomNumber >= 20 && randomNumber <= 30) {
	//		// to ready 

	//		RDY->insertend(p);

	//	}
	//	else if (randomNumber >= 50 && randomNumber <= 60)

	//		//to TRM list
	//	{

	//	}
	//}



	void ScheduleAlgo() {


		if (RDY->countall() != 0)
		{
			LinkedList<Process>* temp = RDY;
			int count = RDY->countall();
			int completed_p = 0;
			//set_Run(nullptr);

			while (completed_p < count)
			{
				check_signal();

				if (get_Run() == nullptr)
				{
					set_Run(RDY->getfirst());
					setState(true);
					completed_p++;
				}
				else
				{
					//call random function
					//manage_process();
					set_Run(nullptr);
					setState(false);

				}
			}
		}
		else
		{
			return;
		}

	}
	void setState(bool state) {

		this->busy = state;
	}
	bool getState() {

		return this->busy;
	}
	//void set_signkill(Queue <Process>* signk);
	//Queue<Process>* get_signkill();
	void check_signal()

	{
		Process p;
		if (p.get_Kill() == currenttime)
		{
			while (!SignKill->isEmpty())
			{

				SignKill->peek(p);
				if (get_Run()->get_Id() == p.get_Id())
				{
					SignKill->DEQUEUE();
					KillProcess(get_Run()->get_Id());

				}
				else if (RDY->getatindex2(p.get_Id())->get_Id() == SignKill->DEQUEUE().get_Id())
					//RDY->getfirst()->get_Id() == SignKill->dequeue().get_Id()
				{
					KillProcess(RDY->getfirst()->get_Id());
				}
				else {
					return;
				}
			}
		}

	}
	void add_to_RDYlist(Process* new_process) {
		RDY->insertend(*new_process);
	}
	LinkedList <Process>* getFCFSreadylist()
	{
		return RDY;
	}
	std::string get_P_name() const {
		return this->ProcessorName;
	}


	~FCFS_P() {
		delete RDY;
		delete SignKill;
	}
};