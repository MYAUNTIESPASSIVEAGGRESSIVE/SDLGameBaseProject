#include "Graphics.h"

Graphics* Graphics::_instance;
bool Graphics::_initialised = false;

// checks instance
Graphics* Graphics::Instance() 
{
	// checks if instance is null
	if (_instance) return _instance;

	// if not null or instance is created returns instance
	return _instance = new Graphics();
}

//clears static memory allaocation
void Graphics::Release() 
{
	// deletes the graphics instance and sets NULL
	delete _instance;
	_instance = NULL;

	//sets initalised to false
	_initialised = false;
}

// checks if initalised
bool Graphics::Initialised() 
{
	return _initialised;
}

//constructor
Graphics::Graphics() 
{
	sdlBackBuffer = NULL;

	_initialised = Init();
}


// destructor
Graphics::~Graphics() 
{
	// destroys the window and makes the window pointer null
	SDL_DestroyWindow(sdlWindow);
	sdlWindow = NULL;

	// destroys the renderer and makes renderer pointer null
	SDL_DestroyRenderer(sdlRenderer);
	sdlRenderer = NULL;

	// quits SDL + external libs
	SDL_Quit();
	TTF_Quit();
}

// function for initalising SDL, the window and the back buffer
bool Graphics::Init() 
{
	// if SDL fails to initalise send error message
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL_Initalisation ERROR : %s/n", SDL_GetError());
		return false;
	}

	// create the window
	sdlWindow = SDL_CreateWindow("SDL TUTORIAL PRACTICE", SCR_WIDTH, SCR_HEIGHT, SDL_EVENT_WINDOW_SHOWN);

	// if window fails to create send error message
	if (sdlWindow == NULL) 
	{
		printf("Window Creation Failed: %s/n", SDL_GetError());
		return false;
	}

	// create the renderer
	sdlRenderer = SDL_CreateRenderer(sdlWindow, NULL);

	if (sdlRenderer == NULL) 
	{
		printf("Renderer Creation Failed: %s/n", SDL_GetError());
		return false;
	}

	// sets the renderer draw colour to white
	SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	if (TTF_Init() == -1) 
	{
		printf("TTF Init Error: %s\n", SDL_GetError());
	}


	// assigns the backbuffer surface with the window
	sdlBackBuffer = SDL_GetWindowSurface(sdlWindow);

	return true;
}

// loading and creating texture from surface
SDL_Texture* Graphics::LoadTexture(std::string filepath)
{
	// texture starts null
	SDL_Texture* texture = NULL;

	// surface is created from the image from a filepath
	SDL_Surface* surface = IMG_Load(filepath.c_str());

	if (surface == NULL)
	{
		printf("Image Load Error: Path(%s) - Error (%s)\n", filepath.c_str(), SDL_GetError());
		return texture;
	}

	// texture is created from the surface
	texture = SDL_CreateTextureFromSurface(sdlRenderer, surface);

	if (texture == NULL)
	{
		printf("Texture Create Error: %s\n", SDL_GetError());
		return texture;
	}

	// free memory by destroying surface
	SDL_DestroySurface(surface);

	// return the created texture
	return texture;
}

SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text)
{
	size_t length = text.size();

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), length, {0,0,0});

	if (surface == NULL)
	{
		printf("Text render error %s\n", SDL_GetError());
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(sdlRenderer, surface);

	if (tex == NULL)
	{
		printf("Text Texture Creation Error %s\n", SDL_GetError());
	}

	SDL_DestroySurface(surface);

	return tex;
}

void Graphics::ClearBackBuffer()
{
	SDL_RenderClear(sdlRenderer);
}

void Graphics::DrawTexture(SDL_Texture* texture, SDL_FRect* clip, SDL_FRect* rend)
{
	SDL_RenderTexture(sdlRenderer, texture, clip, rend);
}

// updates the window surface (Acts like a Refresh)
void Graphics::Render() 
{
	SDL_RenderPresent(sdlRenderer);
}