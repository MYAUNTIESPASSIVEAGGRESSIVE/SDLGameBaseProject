#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include <SDL3/SDL.h>

class InputManager
{

private:

	static InputManager* _instance;

	const bool* _iKeyboardStates;

public:

	static InputManager* Instance();
	static void Release();

	bool KeyDown(SDL_Scancode scanCode);

	void Update();

private:

	InputManager();
	~InputManager();


};

#endif


