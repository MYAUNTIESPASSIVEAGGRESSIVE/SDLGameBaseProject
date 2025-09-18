#ifndef _TIMER_H
#define _TIMER_H

#include <SDL3/SDL.h>

class Timer
{

// private variables
// timer instance and ints/floats
private:
	// timer instance var
	static Timer* _instance;

	Uint32 _startTicks;
	Uint32 _elapsedTicks;

	float _deltaTime;
	float _timeScale;

// public functions
public:

	// instance creator and release funcs
	static Timer* Instance();
	static void Release();
	// resets values
	void Reset();

	// gets deltatime
	float DeltaTime();

	// sets timescale
	void TimeScale(float t);

	// gets timescale
	float TimeScale();


	void Update();

	// private functions
private:

	// con and dest funcs
	Timer();
	~Timer();

};

#endif // (_TIMER_H)


