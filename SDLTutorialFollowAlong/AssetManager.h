#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H
#include "Graphics.h"
#include <map>


class AssetManager
{
private:
	// instance ptr
	static AssetManager* _instance;

	// map for assets
	std::map<std::string, SDL_Texture*> _aTextures;

	std::map<std::string, SDL_Texture*> _aText;

	std::map<std::string, TTF_Font*> _aFont;

public:

	// instance func and release func
	static AssetManager* Instance();
	static void Release();

	// get texture
	SDL_Texture* GetTexture(std::string filename);

	SDL_Texture* GetText(std::string text, std::string filename, int size);

private:

	// const and dest
	AssetManager();
	~AssetManager();

	TTF_Font* GetFont(std::string filename, int size);
};

#endif // !_ASSETMANAGER_H


