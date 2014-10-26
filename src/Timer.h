#pragma once
#ifndef _DARK_ENGINE_TIMER_H_
#define _DARK_ENGINE_TIMER_H_
class Timer
{
public:

	float totalTime() const;  // in seconds
	float deltaTime() const; // in seconds

	void reset(); // Call before message loop.
	void start(); // Call when unpaused.
	void stop();  // Call when paused.
	void tick();  // Call every frame.

private:
	Timer();
	Timer(const Timer&);
	Timer& operator=(const Timer&);

	static Timer instance;

	double secondsPerCount;
	double _deltaTime;

	__int64 baseTime;
	__int64 pausedTime;
	__int64 stopTime;
	__int64 prevTime;
	__int64 currTime;

	bool stopped;

public:
	static Timer& getInstance();
};
#endif
