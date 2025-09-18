#include "InputManager.h"

InputManager* InputManager::_instance = NULL;

InputManager* InputManager::Instance()
{
	if (_instance == NULL)
		_instance = new InputManager();

	return _instance;
}

void InputManager::Release()
{
	delete _instance;
	_instance = NULL;
}

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

// returns a scancode of the keyboard input
bool InputManager::KeyDown(SDL_Scancode scanCode)
{
	return _iKeyboardStates[scanCode];
}

// assigns the got keyboard state into the keyboardstates var
void InputManager::Update()
{
	_iKeyboardStates = SDL_GetKeyboardState(NULL);
}