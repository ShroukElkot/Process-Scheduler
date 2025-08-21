#pragma once
#ifndef SJF_P_H
#define SJF_P_H
#include "Processor.h"
#include "Process.h"
//#include "Controller.h"
#include "operation.h"
#include "Priority_queue.cpp"
#include <string>
#include <iostream>
using namespace std;


class SJF_P : public Processor //, public operation
{
private:
	//Priority_queue <Process>* RDY;
	Priority_queue<Process>* RDY;
	bool busy;
	std:: string ProcessorName;
public:
	SJF_P();
	SJF_P(std::string name);
	
	//SJF_P(controller* pCont);
	virtual ~SJF_P();
	SJF_P(Process* P, double priority);
	void add_to_RDYlist(Process* new_process);
	void setState(bool state);
	bool getState();
	Priority_queue<Process>* getSJFreadylist();
	void ScheduleAlgo();
	std::string get_P_name() const;
};

#endif // !SJF_P_H