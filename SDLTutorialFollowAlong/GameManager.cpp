#include "GameManager.h"

GameManager* GameManager::_instance = NULL;

// creates instance if null
GameManager* GameManager::Instance() 
{
	// checks if instance is null
	if (_instance == NULL)
	{
		// if null create instance
		_instance = new GameManager();
	}

	// if not null or instance is created returns instance
	return _instance;
}

//clears static memory allaocation
void GameManager::Release()
{
	// deletes the graphics instance and sets NULL
	delete _instance;
	_instance = NULL;
}

// constructor
GameManager::GameManager()
{
	// quit is set to false
	_mQuit = false;

	// graphics pointer is set to the graphics class instance
	_mGraphics = Graphics::Instance();

	// if the graphics are not initalised then quit is true and the proj closes
	if (!Graphics::Initialised()) 
	{
		_mQuit = true;
	}

	// assinging ptr to instance
	_mAssetManager = AssetManager::Instance();

	_mInputManager = InputManager::Instance();

	// assigning timer pointer to current timer instance
	_mTimer = Timer::Instance();

	_mTexture = new Texture("Hello World!", "Ithaca-LVB75.TTF", 60);
	_mTexture2 = new Texture("Hello World!", "Ithaca-LVB75.TTF", 60);

	// for animated texture do something like this:
	// _mAnimText = new AnimatedTexture("filename.png", 125, 45, 40, 38, 4, 3.0f, animatedtexture::horizontal)

	_mTexture->SetPos(Vector2(Graphics::SCR_WIDTH * 0.5f, Graphics::SCR_HEIGHT * 0.5f));
	_mTexture2->SetPos(Vector2(400, 400));
}

// destructor
GameManager::~GameManager() 
{

	AssetManager::Release();
	_mAssetManager = NULL;

	// triggers the release function for graphics and unassigns the graphics var
	Graphics::Release();
	_mGraphics = NULL;

	InputManager::Release();
	_mInputManager = NULL;

	Timer::Release();
	_mTimer = NULL;

	delete _mTexture;
	_mTexture = NULL;

	delete _mTexture2;
	_mTexture2 = NULL;
}

// game loop/event polling
void GameManager::Run() 
{
	// while quit is NOT true
	while (!_mQuit) 
	{

		// timer updates per iteration of the while loop
		_mTimer->Update();

		// 0 is the quit event
		while (SDL_PollEvent(&_sdlEvents) != 0) 
		{
			if (_sdlEvents.type == SDL_EVENT_QUIT) 
			{
				_mQuit = true;
			}
		}
		
		// if the timer is lower than 1/frame rate 
		if (_mTimer->DeltaTime() >= (1.0f / FRAME_RATE))
		{
			//check for input
			_mInputManager->Update();

			if (_mInputManager->KeyDown(SDL_SCANCODE_W)) {
				_mTexture->Translate(Vector2(0.0f, -20.0f) * _mTimer->DeltaTime());
			}

			// first clear the back buffer
			_mGraphics->ClearBackBuffer();

			_mTexture->Render();
			_mTexture2->Render();

			// do render func
			_mGraphics->Render();

			// reset the values
			_mTimer->Reset();
		}
	}
}