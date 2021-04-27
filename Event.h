#ifndef  EVENT_H_
#define EVENT_H_	
class Event
{
public:
	explicit Event(size_t time);
	~Event();

	virtual void Execute() = 0;
	
protected:
	size_t time_ = 0;
	
};

#endif


