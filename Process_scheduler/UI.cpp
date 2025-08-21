#include "UI.h"
#include "Definitions.h"
#include <conio.h>
using namespace std;
#include <string>
UI::UI() {
	ApplicationMode = Mode::interactive;
	setMode();

}

void UI::setMode() {
	int modeNum = -1;
	cout << "------------------------------------------" << endl;
	cout << "Please Choose Your Interface Mode: \n [1] For Interactive Mode \n [2] For Step-By-Step \n [3] For Silent Mode \n " << endl;
	cout << "------------------------------------------" << endl;
	cin >> modeNum;
	while (modeNum > 3 || modeNum < 1) {
		cout << "Please Enter A Valid Number: " << endl;
		cin >> modeNum;
	}
	switch (modeNum) {
	case 1:
		ApplicationMode = Mode::interactive;
		break;
	case 2:
		ApplicationMode = Mode::step_by_step;
		break;
	case 3:
		ApplicationMode = Mode::silent;
		break;
	default:
		ApplicationMode = Mode::interactive;
		break;
	}
}

Mode UI::GetCurrentMode()const {

	return ApplicationMode;
}

//void UI::IntercativeModeOutput(string Message) const {
//
//	cout << Message << endl;
//	_getch();
//}

void UI::printMessage(string Message) const {
	if (ApplicationMode == Mode::interactive) {
		IntercativeModeOutput(Message);
	}
}
string UI::getInput()
{
	string filename;
	cout << "Enter file name" << endl;
	cin >> filename;
	return filename;
}

void UI::Print(Scheduler* s) //interactuve mode 
{
	 cout << "Current timestep " << s->getCurrentTime();
	 //------------------------------------------Printing RDY lists-----------------------------------
	 cout << "----------------------- RDY Processes-------------------------" << endl; 
	 for (int i = 0; i < s->getFCFSlists()->countall(); i++)
	 {
		 string name = s->getFCFSlists()->getatindex(i).get_P_name();
		 LinkedList<Process>* FCFS_RDY = s->getFCFSlists()->getatindex1(i).getFCFSreadylist();
		 int no_of_Processes = FCFS_RDY->countall();
		 cout << name << "[FCFS]:" << no_of_Processes<< "RDY:" <<"";
		 for (int j = 0; j < FCFS_RDY->countall(); i++)
		 {
			 int r_f = FCFS_RDY->getatindex(j).get_Id();
			 cout << r_f << " ";
		 }
	 }
	 for (int i = 0; i < s->getRRlist()->countall(); i++)
	 {
		 string name = s->getRRlist()->getatindex(i).get_P_name();
		 LinkedList<Process>* RR_RDY = s->getRRlist()->getatindex1(i).getRRreadylist();
		 int no_of_Processes = RR_RDY->countall();
		 cout << name << "[RR]:" << no_of_Processes << "RDY:" << "";
		 for (int j = 0; j < RR_RDY->countall(); i++)
		 {
			 int r = RR_RDY->getatindex(j).get_Id();
			 cout << r << " ";
		 }
	 }
	 for (int i = 0; i < s->getSJFlist()->countall(); i++)
	 {
		 string name = s->getSJFlist()->getatindex(i).get_P_name();
		 Priority_queue<Process>* SJF_RDY = s->getSJFlist()->getatindex1(i).getSJFreadylist();
		 int no_of_Processes = SJF_RDY->getCount();
		 cout << name << "[SJF]:" << no_of_Processes << "RDY:" << "";
		 for (int j = 0; j < SJF_RDY->getCount(); i++)
		 {
			 int r = SJF_RDY->get_at_node(j).get_Id();
			 cout << r << " ";
		 }
	 }
	 
	 //------------------------------------------Printing BLK list-----------------------------------
	 Priority_queue <Process>* block = s->getBlockList();
	 cout << "----------------------- BLK Processes-------------------------" << endl; 
	 int no_blk = block->getCount();
	 cout << no_blk <<" "<< "BLK" ;
	 for (int i = 0; i < block->getCount();i++)
	 {
		 int p = block->get_at_node(i).get_Id();
		 cout << p << " ";
	 }

	 //-----------------------------------------Printing RUN processes---------------------------------
	 cout <<"RUN:" << " ";
	 for (int i = 0; i < s->getFCFSlists()->countall(); i++)
	 {
		 string name = s->getFCFSlists()->getatindex(i).get_P_name();
		 int FCFS_RUN = s->getFCFSlists()->getatindex1(i).get_Run()->get_Id();
		 cout << FCFS_RUN << "("<< name << ")" << "";
	 }
	 for (int i = 0; i < s->getRRlist()->countall(); i++)
	 {
		 string name = s->getRRlist()->getatindex(i).get_P_name();
		 int RR_RUN = s->getRRlist()->getatindex1(i).get_Run()->get_Id();
		 cout << RR_RUN << "(" << name << ")" << "";
	 }
	 for (int i = 0; i < s->getSJFlist()->countall(); i++)
	 {
		 string name = s->getSJFlist()->getatindex(i).get_P_name();
		 int SJF_RUN = s->getSJFlist()->getatindex1(i).get_Run()->get_Id();
		 cout << SJF_RUN << "(" << name << ")" << "";

	 }

	 //-------------------------------------------Printing TRM list---------------------------------
	 LinkedList<Process>* terminated = s->getTRMList();
	 cout << "----------------------- TRM Processes-------------------------" << endl; 
	 int no_trm = terminated->countall();
	 cout << no_trm << " " << "TRM";
	 for (int i = 0; i < terminated->countall(); i++)
	 {
		 int t = terminated->getatindex(i).get_Id();
		 cout << t << " ";
	 }






}