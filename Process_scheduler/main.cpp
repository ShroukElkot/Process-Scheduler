#include "SJF_P.h"
using namespace std;
#include<iostream>
#include "Scheduler.h"
#include "Process.h"

int main()
{
	UI callGUI; 
	Scheduler s;
	/*s.Simulator();*/

	//forr loop on scheduler updates

	callGUI.Print(&s);
	/*Process p(1);
	SJF_P<int> P1(p,1.2);
	
	P1.ScheduleAlgo();*/
}