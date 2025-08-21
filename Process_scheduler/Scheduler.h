#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Queue.h"
#include "Priority_queue.h"
#include "LinkedList.h"
#include "Processor.h"
#include "Process.h"
#include "FCFS_P.h"
#include "RR_P.h"
#include "SJF_P.h"


class Scheduler
{
private: 
	Queue<Process>* NewList;
	Priority_queue <Process>* BLKlist;
	LinkedList <Process>* TRMlist;
	//LinkedList<Processor*>* Processors_list;
	//Processor** Processors_list;
	
	LinkedList<FCFS_P>* FCFS_list;
	LinkedList<RR_P>* RR_list;
	LinkedList<SJF_P>* SJF_list;


	//LinkedList<Processor*>* list_of_processors;
	//FCFS_P* Processor1;
	int current_time;
	int no_fcfs;
	int no_sjf;
	int no_rr;
	/*Queue<Process>* RdyList1;
	Queue<Process>* RdyList2;
	Queue<Process>* RdyList3;
	Queue<Process>* RdyList4;
	Queue<Process>* RdyList5;*/
	//Processor* list;


public:
	Scheduler();
	//Scheduler(Queue<Process>& newlist);
	void distributeNewList();
	//Scheduler() { Newlist = new Queue<Process>(); };
	~Scheduler();
	void fill_processors_list();
	void readnumofprocessors(string& filename);

	void AddProcessToNew(Process* p);
	void LoadProcesses(Queue<Process>* List);
	void FillReady();

	void HandleRDY();
	void AddToReady(Process* p);
	void MoveToBLK(Process* P);
	void RequestI_O(Process* P);
	void MoveToTRM(Process* P);
	void manage_process(Process* p);
	void Simulator();

	Priority_queue <Process>* getBlockList();
	LinkedList <Process>* getTRMList();
	LinkedList<FCFS_P>* getFCFSlists();
	LinkedList<RR_P>* getRRlist();
	LinkedList<SJF_P>* getSJFlist();
	int getCurrentTime();

};

#endif // !SCHEDULER_H