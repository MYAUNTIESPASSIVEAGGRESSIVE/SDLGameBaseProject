#ifndef _TEXTURE_H
#define _TEXTURE_H
#include "EntityBase.h"
#include "AssetManager.h"

// inherits EntityBase
class Texture : public EntityBase
{
protected:

	// texture ptr
	SDL_Texture* _tTexture;

	// graphics ptr
	Graphics* _tGraphics;

	// float for texture height and width
	float _tWidth;
	float _tHeight;

	// bool checking if the texture is clipped
	bool _tIsClipped;

	// rects that check the render size and clip size
	SDL_FRect _tRenderRect;
	SDL_FRect _tClipRect;

public:

	// const and dest
	Texture(std::string filepath);
	Texture(std::string filepath, int x, int y, int w, int h);
	Texture(std::string text, std::string fontpath, int size);
	~Texture();

	// virtual render void func
	// note: virtual as to inherit if needed just in case
	virtual void Render();
};

#endif
