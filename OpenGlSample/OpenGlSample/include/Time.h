#pragma once
#include <Windows.h>

class Time
{ 
private:
	int frame;
	int count;
	double _perFrame;
	LARGE_INTEGER _frameInfo;
	LARGE_INTEGER _prevFrameCounter;
	LARGE_INTEGER _nowFrameCounter;

	static Time* instance;
	
	Time();
	
public:	
	static Time* GetInstance()
	{
		if (instance == 0)
		{
			instance = new Time();
		}		
		return instance;
	};
	
	bool IsFixedRendering();
};

