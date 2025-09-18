#include "Timer.h"

Timer* Timer::_instance = NULL;

Timer* Timer::Instance() 
{
	// checks if instance is null
	if (_instance == NULL)
	{
		// if null create instance
		_instance = new Timer();
	}

	// if not null or instance is created returns instance
	return _instance;
}

// releases the instance
void Timer::Release() 
{
	delete _instance;
	_instance = NULL;
}

//constructor
Timer::Timer() 
{
	// resets values
	Reset();
	// sets timescale to 1.0
	_timeScale = 1.0f;
}


//destructor
Timer::~Timer()
{

}

// resets all values
void Timer::Reset()
{
	_startTicks = SDL_GetTicks(); //SDL_GetTicks - gets num of milliseconds since lib initalised
	_elapsedTicks = 0;
	_deltaTime = 0.0f;
}

// returns deltatime
float Timer::DeltaTime() 
{
	return _deltaTime;
}

// sets timescale
// setting to 0 pauses the game and then speeds up depending on float input
void Timer::TimeScale(float t) 
{
	_timeScale = t;
}

// gets timescale
float Timer::TimeScale()
{
	return _timeScale;
}

void Timer::Update()
{
	// ticks that happens between last reset and current time
	_elapsedTicks = SDL_GetTicks() - _startTicks;

	// delta time is elapsed ticks in seconds since get ticks is in milliseconds
	_deltaTime = _elapsedTicks * 0.001f;
}