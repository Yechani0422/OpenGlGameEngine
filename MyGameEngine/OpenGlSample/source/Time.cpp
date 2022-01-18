#include "../include/Time.h"
#include <iostream>
Time* Time::instance = 0;

Time::Time()
{
	frame = 60;
	count = 0;
	QueryPerformanceFrequency(&_frameInfo);
	QueryPerformanceCounter(&_prevFrameCounter);

	// fps 60 ∞Ì¡§.
	_perFrame = (double)_frameInfo.QuadPart / frame;
	std::cout << _perFrame << std::endl;
}

bool Time::IsFixedRendering()
{
	QueryPerformanceCounter(&_nowFrameCounter);
	double time_distance = (double)_nowFrameCounter.QuadPart - (double)_prevFrameCounter.QuadPart;
	if (time_distance > _perFrame)
	{
		_prevFrameCounter = _nowFrameCounter;

		count++;
		if(frame== count)
		{
			std::cout << "1√ " << std::endl;	
			count = 0;
		}
		
		return true;
	}
	std::cout<<"Dis:"<<time_distance<<" Fps:" <<1/ (time_distance / (double)_frameInfo.QuadPart) << std::endl;
	return false;
}