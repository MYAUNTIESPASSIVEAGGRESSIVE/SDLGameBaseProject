#include "AssetManager.h"

AssetManager* AssetManager::_instance = NULL;

AssetManager* AssetManager::Instance()
{
	if (_instance == NULL)
		return new AssetManager();

	return _instance;
}

void AssetManager::Release()
{
	delete _instance;
	_instance = NULL;
}

// const
AssetManager::AssetManager()
{

}

// dest
AssetManager::~AssetManager()
{
	// checks the map of textures
	for (auto texture : _aTextures)
	{
		// if the texture is null then destroy
		if (texture.second != NULL)
		{
			SDL_DestroyTexture(texture.second);
		}
	}

	// clears the texture map
	_aTextures.clear();

	// gets the amount of text textures and destroys them
	for (auto text : _aText)
	{
		if (text.second != NULL)
		{
			SDL_DestroyTexture(text.second);
		}
	}

	// gets the font ptrs and destroys them
	for (auto font : _aFont)
	{
		if (font.second != NULL)
		{
			TTF_CloseFont(font.second);
		}
	}

	// clears the font map
	_aFont.clear();
}

// gets a texture using the filename
SDL_Texture* AssetManager::GetTexture(std::string filename)
{
	// gets the exe location and searches for the filename in the assets folder
	std::string fullpath = SDL_GetBasePath();
	fullpath.append("Assets\\" + filename);

	// if the texture is nullptr
	if (_aTextures[fullpath] == nullptr)
	{
		// load the texture
		_aTextures[fullpath] = Graphics::Instance()->LoadTexture(fullpath);
	}

	return _aTextures[fullpath];
}

// gets the font
TTF_Font* AssetManager::GetFont(std::string filename, int size)
{
	// the fullpath of the assets folder
	std::string fullpath = SDL_GetBasePath();
	fullpath.append("Assets\\" + filename);

	// gives a key unique to the filename + size
	std::string key = fullpath + (char)size;

	// if the font with key isnt there then it tries to create a font from the file
	if (_aFont[key] == nullptr)
	{
		_aFont[key] = TTF_OpenFont(fullpath.c_str(), size);

		// if it cant do either then it returns an error message
		if (_aFont[key] == nullptr)
			printf("Font Loading Error: Font -%s Error: -%s", filename.c_str(), SDL_GetError());
	}

	return _aFont[key];
}

// gets a texture
SDL_Texture* AssetManager::GetText(std::string text, std::string filename, int size)
{
	// gets the font
	TTF_Font* font = GetFont(filename, size);

	// creates the key
	std::string key = text + filename + (char)size;

	// if texture[key] not there then create text using the font and text string
	if (_aText[key] == nullptr)
	{
		_aText[key] = Graphics::Instance()->CreateTextTexture(font, text);
	}

	return _aText[key];
}