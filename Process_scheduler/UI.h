#pragma once
#include <iostream>
#include <string>
#include "Definitions.h"
#include "Scheduler.h"

using namespace std;

class UI {
private:
	Mode ApplicationMode;

public:
	UI();
	//UI();
	void setMode();
	Mode GetCurrentMode() const;
	void printMessage(string message) const;
	void IntercativeModeOutput(string message) const;
	string getInput();
	void Print(Scheduler* s);

};