#pragma once
#include "Queue.h"
#include <iostream>
#include <fstream>
#include "Queue.cpp"
#include <string>
#include <sstream>
#include "Node.cpp"

struct I_O_pairs
{
	int I_O_R;
	int I_O_D;
};


class Process
{
private:
	int AT;
	int ID;
	int CT;
	int N;  // Process ID, Arrive time , CPU time , Number of time the process request I/O
	Queue <I_O_pairs>* I_O_pair; //Queue of struct 
	Queue<Process>* newList;
	
public:
	Process();
	bool request, run; 
	int killTime;
	Process(int AT, int ID, int CT, int N, Queue <I_O_pairs>* I_O_pair);
	void loadprocess(const string& filename, Queue<Process>& newlist);
	Queue<Process>* getNewList();
	//friend std::ostream& operator<<(std::ostream& os, const Process& p);
	
	bool IsRequest();
	void setRequest(bool R);
	bool IsRun();
	void setRun(bool R);
	int getI_O_D();
	int getI_O_R();
	int getAT();
	int getCT();
	void setNo_of_requests(int n);
	int getNo_of_requests();
	int get_Kill();
	
	int get_Id();
	friend std::ostream& operator<<(std::ostream& os, const Process& p);


};