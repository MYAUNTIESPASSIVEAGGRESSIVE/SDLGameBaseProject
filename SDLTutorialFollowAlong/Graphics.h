#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <stdio.h>

class Graphics
{
public:

	// constant static variables for the screens width and height
	static const int SCR_WIDTH = 800;
	static const int SCR_HEIGHT = 600;

private:

	// graphics class instance
	static Graphics* _instance;
	// bool for initalisation
	static bool _initialised;

	SDL_Window* sdlWindow;
	SDL_Surface* sdlBackBuffer;

	SDL_Renderer* sdlRenderer;

//public functions
public:
	// returns instance of class
	static Graphics* Instance();

	// clears static memory aloc
	static void Release();

	static bool Initialised();

	// loads textures
	SDL_Texture* LoadTexture(std::string path);

	// creating a ttf texture
	SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text);

	// clears canvas on every frame
	void ClearBackBuffer();

	// called by classes needing texture and give it a texture to draw
	void DrawTexture(SDL_Texture* texture, SDL_FRect* clip,  SDL_FRect* rend = NULL);

	// refresh function for drawing
	void Render();

//private functions
private:
	//constructor
	Graphics();

	//destructor
	~Graphics();

	//initialisation function
	bool Init();

};

#endif // (_GRAPHICS_H)

