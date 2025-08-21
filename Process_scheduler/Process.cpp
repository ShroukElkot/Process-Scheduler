#include "Process.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include "Queue.cpp"
#include <string>
#include <sstream>
#include "UI.h"

Process::Process() {
	AT = 0;
	ID = 0;
	CT = 0;
	N = 0;
	I_O_pair = nullptr;
	newList = nullptr;
}

Process::Process(int at, int id, int ct, int n, Queue <I_O_pairs>* I_O_pair_c) :
	AT(at), ID(id), CT(ct), N(n), I_O_pair(I_O_pair_c), newList(nullptr) {};



void Process::loadprocess(const string& filename, Queue<Process>& newlist) {
	UI gUI;
	string Filename = gUI.getInput();
	Filename = filename;
	ifstream infile(filename);
    string line;
    int count = 0;

    while (getline(infile, line)) {
        if (count >= 4) {
            stringstream ss(line);
            int at, id, ct, n, I_O_r, I_O_d;
            char io_separator;
            ss >> at >> id >> ct >> n >> I_O_r >> io_separator >> I_O_d;
            //I_O_pair io_pair = { I_O_r, I_O_d };
            // *this = Process (at, id, ct, n, io_pair);
			I_O_pairs pair;
			pair.I_O_D = I_O_d;
			pair.I_O_R = I_O_r;
			I_O_pair->enqueue(pair);
            Process process(at, id, ct, n, I_O_pair);
            newlist.enqueue(process);
        }

        count++;
    };
}

Queue<Process>* Process::getNewList()
{
    return newList;
}
//std::ostream& operator<<(std::ostream& os, const Process& p)
//{
//    os << ", Arrival Time: " << p.AT << "Process ID: " << p.ID << "CPU time " << p.CT << "Number of time the process request I/O" << p.N << std::endl;
//    return os;
//}

bool Process::IsRequest()
{
	return this->request;
}


void Process ::setRequest(bool R)
{
	request = R;
}

bool Process::IsRun()
{
	return run;
}


void Process::setRun(bool R)
{
	run = R;
}
//--------------- Dequeue needs replace
int Process::getI_O_D()
{
	return I_O_pair->PeekValue().I_O_D;
}

int Process::getI_O_R()
{
	return I_O_pair->PeekValue().I_O_R;
}

int Process::getCT()
{
	return this->CT;
}

int Process::getAT()
{
	return this->AT;
}


void Process::setNo_of_requests(int n)
{
	N = n;
}

int Process::getNo_of_requests()
{
	return this->N;
}

int Process::get_Kill() {
	return this->killTime;
}

int Process::get_Id()
{
	return this->ID;
}

std::ostream& operator<<(std::ostream& os, const Process& p) {
	os << "Process ID: " << p.ID << ", Arrival Time: " << p.AT << ", CPU Time: " << p.CT << ", Number of I/O Requests: " << p.N;
	return os;
}