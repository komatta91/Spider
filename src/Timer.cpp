#include "Timer.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

Timer Timer::instance;

Timer::Timer()
	: secondsPerCount(0.0), _deltaTime(-1.0), baseTime(0),
	pausedTime(0), prevTime(0), currTime(0), stopped(false)
{
	__int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	secondsPerCount = 1.0 / (double)countsPerSec;
}

float Timer::totalTime()const
{
	if( stopped )
	{
		return (float)(((stopTime - pausedTime) - baseTime) * secondsPerCount);
	}

	else
	{
		return (float)(((currTime - pausedTime) - baseTime) * secondsPerCount);
	}
}

float Timer::deltaTime() const
{
	return (float)_deltaTime;
}

void Timer::reset()
{
	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

	baseTime = currTime;
	prevTime = currTime;
	stopTime = 0;
	stopped  = false;
}

void Timer::start()
{
	__int64 startTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);

	// Accumulate the time elapsed between stop and start pairs.
	//
	//                     |<-------d------->|
	// ----*---------------*-----------------*------------> time
	//  mBaseTime       mStopTime        startTime

	if( stopped )
	{
		pausedTime += (startTime - stopTime);

		prevTime = startTime;
		stopTime = 0;
		stopped  = false;
	}
}

void Timer::stop()
{
	if( !stopped )
	{
		__int64 currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

		stopTime = currTime;
		stopped  = true;
	}
}

void Timer::tick()
{
	if( stopped )
	{
		_deltaTime = 0.0;
		return;
	}

	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
	currTime = currTime;

	_deltaTime = (currTime - prevTime)*secondsPerCount;

	prevTime = currTime;

	if(_deltaTime < 0.0)
	{
		_deltaTime = 0.0;
	}
}

Timer& Timer::getInstance()
{
	return Timer::instance;
}