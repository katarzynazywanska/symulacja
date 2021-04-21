#pragma once
#include "User.h"
#include "Process.h"
#include "ResourceBlock.h"

class Event
{
public:
	double schedule_time = 0;
	Process* p; 
	
	Event(Process* ptr);
};

Event :: Event(Process* ptr) {
	schedule_time = -1.0;
	p = ptr;
}
