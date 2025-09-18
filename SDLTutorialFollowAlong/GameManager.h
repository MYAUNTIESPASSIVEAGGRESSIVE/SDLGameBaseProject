#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "AnimatedTexture.h"
#include "InputManager.h"

class GameManager
{
	// priv variables
private:
	// game manager instance
	static GameManager* _instance;

	const int FRAME_RATE = 60;

	// quit bool
	bool _mQuit;

	// graphics pointer
	Graphics* _mGraphics;

	// asset manager ptr
	AssetManager* _mAssetManager;

	InputManager* _mInputManager;

	// used for event pooling
	SDL_Event _sdlEvents;

	//timer pointer
	Timer* _mTimer;

	// texture class ptr
	AnimatedTexture* _mAnimTexture;

	Texture* _mTexture;
	Texture* _mTexture2;

	//public funcs
public:
	// class instance
	static GameManager* Instance();

	// clearing static memory alloc
	static void Release();

	//
	void Run();

	// priv funcs
private:
	//constructor
	GameManager();

	//destructor
	~GameManager();
};

#endif //(_GAMEMANAGER_H)

