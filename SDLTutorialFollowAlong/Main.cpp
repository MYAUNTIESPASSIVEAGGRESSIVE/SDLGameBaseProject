// external libs
#include <iostream>
#include <SDL3/SDL.h>

// internal headers
#include "GameManager.h"

int main() 
{
	// creates a game manager instance
	GameManager* gameManager = GameManager::Instance();
	// calls the run function
	gameManager->Run();

	GameManager::Release();
	gameManager = NULL;

	return 0;
}