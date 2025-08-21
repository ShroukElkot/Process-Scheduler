#pragma once
#include "Processor.h"
#include "Queue.cpp"
#include "LinkedList.h"
#include "Process.h"
#include "Node.cpp"
#include "operation.h"
#include <string>
#include <iostream> 
using namespace std;

class RR_P : public Processor //, public operation
{
private:
	LinkedList <Process>* RDY;
	bool busy;
	int timeslice;
	std::string ProcessorName;
	//int totalcputime;
public:
	RR_P();
	RR_P(std::string name);
	//RR_P(LinkedList<T>* RDY, bool state, int timeslice);
	int calc_total_CPUT();
	void ScheduleAlgo();
	void add_to_RDYlist(Process* new_process);
	void setState(bool state);
	bool getState();
	LinkedList <Process>* getRRreadylist();
	std::string get_P_name() const;
	~RR_P();
};





