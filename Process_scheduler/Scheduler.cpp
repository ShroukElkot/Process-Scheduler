#ifndef SCHEDULER_CPP
#define SCHEDULER_CPP

#include "Scheduler.h"

#include <cstdlib>
#include <ctime>
#include "Definitions.h"
#include <iostream>
using namespace std;


Scheduler::Scheduler()
{
	current_time = 0;
	no_fcfs = no_sjf = no_rr = 0;

	NewList = nullptr;
	BLKlist = nullptr;
	TRMlist = nullptr;
	FCFS_list = nullptr;
	RR_list = nullptr;
	SJF_list = nullptr;
	
}

//Scheduler::Scheduler(Queue<Process>& newlist) : NewList(newlist) {};



void Scheduler ::AddProcessToNew(Process* p) 
{
	if (NewList == nullptr)
		NewList = new Queue<Process>();
	NewList->ENQUEUE(p);
}

void Scheduler :: LoadProcesses(Queue<Process>* List)
{
	NewList = List;
}


void Scheduler ::readnumofprocessors(string& filename)
{
	ifstream infile(filename);
	string line;
	if (getline(infile, line)) {
		istringstream iss(line);
		int num_fcfs, num_rr, num_sjf;
		iss >> num_fcfs >> num_rr >> num_sjf;
		no_fcfs = num_fcfs;
		no_rr = num_rr;
		no_sjf = num_sjf;
	}

}

void Scheduler ::AddToReady(Process* p) //return to the least processor's RDY list (use the counter in the DS)
{
	FCFS_list->getatindex1(0).add_to_RDYlist(p);
	
}



void Scheduler::FillReady()
{
	Process p;
	NewList = p.getNewList();
	
	int num_processor_types = 3;
	//Processors_list = new Processor<Process> * [num_processor_types];
	//FCFS_list = new FCFS_P* [no_fcfs];
	//RR_list = new RR_P * [no_rr];

	FCFS_list = new LinkedList<FCFS_P>;
	for (int i = 1; i <= no_fcfs; i++) {
		FCFS_P* Processor = new FCFS_P("Processor " + to_string(i));
		FCFS_list->insertend(*Processor);
	}
	RR_list = new LinkedList<RR_P>;
	for (int i = no_fcfs+1; i <= no_fcfs + no_rr; i++) {
		//RR_list[i] = new LinkedList<RR_P>();
		RR_P* Processor = new RR_P("Processor " + to_string(i));
		RR_list->insertend(*Processor);
	}
	
	//SJF_list = new SJF_P * [no_sjf];
	SJF_list = new LinkedList<SJF_P>;
	for (int i = no_fcfs + no_rr + 1; i <= no_fcfs + no_rr + no_sjf; i++) {
		//SJF_list[i] = new LinkedList<SJF_P>();
		SJF_P* Processor = new SJF_P("Processor " + to_string(i));
		SJF_list->insertend(*Processor);
	}


	while (NewList->isEmpty() == false)  // stop when all processes are removed fron NEW
	{
		for (int i = 0; i < no_fcfs; i++)
		{
			Process* ready = NewList->dequeue();
			FCFS_list->getatindex1(i).add_to_RDYlist(ready);
				//->getatindex1(i).add_to_RDYlist(ready);
			
			//FCFS_list[i]->insertend(ready);
		}
		for (int i = 0; i < no_rr; i++)
		{
			Process* ready = NewList->dequeue();
			RR_list->getatindex1(i).add_to_RDYlist(ready);
			//RR_list[i]->insertend(ready);
		}
		for (int i = 0; i < no_sjf; i++)
		{
			Process* ready = NewList->dequeue();
			SJF_list->getatindex1(i).add_to_RDYlist(ready);
			//SJF_list[i]->Enqueue(ready);
		}
	}
	//for (int i = 0; i < no_fcfs; i++)
	//{
	//	LinkedList<Process>* l = FCFS_list[i]->getatindex1(i).getFCFSreadylist();
	//	
	//	//FCFS_list[i]->getatindex1(i).getFCFSreadylist()->PrintList(*l);
	//	/*LinkedList <Process>* to_print = Processors_list[FCFS][i].get_RDYlist();
	//	to_print->PrintList();*/
	//}
	//for (int i = 0; i < no_rr; i++)
	//{
	//	LinkedList<Process>* l = RR_list[i]->getatindex1(i).getRRreadylist();
	//	RR_list[i]->getatindex1(i).getRRreadylist()->PrintList(*l);
	//}
	//for (int i = 0; i < no_sjf; i++)
	//{
	//	//SJF_list[i]->getatindex1(i).getSJFreadylist()->print();
	//}

}
	

void Scheduler ::MoveToBLK(Process* P)
{
	if (BLKlist == nullptr)
		BLKlist = new Priority_queue<Process>();

	BLKlist->Enqueue(P, P->getCT()); // ct is priority
}





void Scheduler ::RequestI_O(Process*P)
{
	//Process process = P;
	int request = P->getI_O_R();
	int request_duration = P->getI_O_D();
	int CT = P->getCT();
	int No_of_requests = P->getNo_of_requests();
	while (P->IsRun())
	{
		if (P->IsRequest() == true)
		{
			BLKlist->Enqueue(P,P->getCT());
			P->setRun(false);
			this->current_time++;
			while (No_of_requests != 0)
			{
				if (CT == (request_duration+request))
				{
					No_of_requests--;
					// add to ready
					AddToReady(P);
				}
			}
			MoveToTRM(P);

		}
		else
		{
			return;
		}
	}
}

void Scheduler ::MoveToTRM(Process* P)
{
	if (TRMlist == nullptr)
		TRMlist = new LinkedList<Process>();

	TRMlist->insertend(*P);
	
}

void Scheduler :: manage_process(Process* p)
{
	srand(time(NULL));
	int randomNumber = rand() % 100 + 1;
	if (randomNumber >= 1 && randomNumber <= 15)	
	{
		// move the process to BLK list
		MoveToBLK(p);
		p->setRun(false);
	}
	else if (randomNumber >= 20 && randomNumber <= 30) 
	{
		// to ready
		AddToReady(p);

	}
	else if (randomNumber >= 50 && randomNumber <= 60)
	{
		//to TRM list
		MoveToTRM(p);
	}
}


void Scheduler ::Simulator()
{
	//LoadProcesses(); //b

	Process p;
	NewList = p.getNewList();
	for (int i = 0; i <= NewList->getCount(); i++) // c(i)
	{
		FillReady();
	}
	for (int i = 0; i < no_fcfs; i++)
	{
		FCFS_list->getatindex1(i).ScheduleAlgo();
	}
	for (int i = 0; i < no_rr; i++)
	{
		RR_list->getatindex1(i).ScheduleAlgo();
		//Processors_list[RR][i].ScheduleAlgo();
	}
	for (int i = 0; i < no_sjf; i++)
	{
		SJF_list->getatindex1(i).ScheduleAlgo();
	}

	int total_processors = no_fcfs + no_rr + no_sjf;
		for (int i = 0; i < total_processors; i++) 
		{
			for (int i = 0; i < no_fcfs; i++)
			{
				Process* current_run = FCFS_list->getatindex1(i).get_Run();
					manage_process(current_run);
			}
			for (int i = 0; i < no_rr; i++)
			{
				Process* current_run = RR_list->getatindex1(i).get_Run();
				manage_process(current_run);
			}
			for (int i = 0; i < no_sjf; i++)
			{
				Process* current_run = SJF_list->getatindex1(i).get_Run();
				manage_process(current_run);
			}

		}

	srand(time(NULL)); //iv
	int randomNumber = rand() % 100 + 1;
	if (randomNumber < 10)
	{
		pair<Process*, double>* P_rand_check = BLKlist->Dequeue();
		
		AddToReady(P_rand_check->first);

	}

	//srand(time(NULL));
	//for (int i = 0; i < no_fcfs; i++)
	//{
	//	//Process ready = NewList->dequeue();
	//	auto ready_FCFS = Processors_list[FCFS][i].get_RDYlist();
	//	int rand_ID = rand() % 30 + 1;
	//	while (ready_FCFS->countall() != 0)
	//	{
	//		Node<Process>* currentNode = ready_FCFS->FINDAT(rand_ID);
	//		int process_id = currentNode->getItemPointer()->get_Id();
	//		FCFS_P for_kill;
	//		for_kill.KillProcess(process_id);
	//		ready_FCFS->deletenode(currentNode->getItem());
	//		break;
	//	}
	//}

		


	
			

}
Priority_queue <Process>* Scheduler::getBlockList()
{
	return BLKlist;
}

LinkedList <Process>* Scheduler :: getTRMList()
{
	return TRMlist;
}

LinkedList<FCFS_P>* Scheduler::getFCFSlists()
{
	return FCFS_list;
}
LinkedList<RR_P>* Scheduler::getRRlist()
{
	return RR_list;
}
LinkedList<SJF_P>* Scheduler:: getSJFlist()
{
	return SJF_list;
}
int Scheduler::getCurrentTime()
{
	return this->current_time;
}


Scheduler::~Scheduler()
{
	delete NewList;
	delete BLKlist;
	delete TRMlist;
	delete FCFS_list;
	delete RR_list;
	delete SJF_list;
}

#endif // !SCHEDULER_CPP

