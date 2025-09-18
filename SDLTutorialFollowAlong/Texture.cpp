#include "Texture.h"

// assigns graphics pointer and texture pointer using load texture func in graphics
Texture::Texture(std::string filename)
{
	_tGraphics = Graphics::Instance();

	_tTexture = AssetManager::Instance()->GetTexture(filename);

	SDL_GetTextureSize(_tTexture, &_tWidth, &_tHeight);

	_tIsClipped = false;

	// sets rect w and h to the texture size w/h
	_tRenderRect.w = _tWidth;
	_tRenderRect.h = _tHeight;
}

// same as other contructor however is used for clipped textures
Texture::Texture(std::string filename, int x, int y, int w, int h)
{
	_tGraphics = Graphics::Instance();

	_tTexture = AssetManager::Instance()->GetTexture(filename);

	_tIsClipped = true;

	_tWidth = w;
	_tHeight = h;

	// sets rect w and h to the texture size w/h
	_tRenderRect.w = _tWidth;
	_tRenderRect.h = _tHeight;

	// sets clip rect to the parsed vars + width and height
	_tClipRect.x = x;
	_tClipRect.y = y;
	_tClipRect.w = _tWidth;
	_tClipRect.h = _tHeight;
}

Texture::Texture(std::string text, std::string fontpath, int size)
{
	_tGraphics = Graphics::Instance();

	_tTexture = AssetManager::Instance()->GetText(text, fontpath, size);

	_tIsClipped = false;

	SDL_GetTextureSize(_tTexture, &_tWidth, &_tHeight);

	_tRenderRect.w = _tWidth;
	_tRenderRect.h = _tHeight;
}

Texture::~Texture()
{
	_tTexture = NULL;
	_tGraphics = NULL;
}

// calls graphics class to draw texture
void Texture::Render()
{
	Vector2 pos = GetPos(world);

	// tells where to render and centers the texture
	_tRenderRect.x = (pos.x - _tWidth * 0.5f);
	_tRenderRect.y = (pos.y - _tHeight * 0.5f);

	_tGraphics->DrawTexture(_tTexture, (_tIsClipped)? &_tClipRect : NULL, & _tRenderRect);
}