#include "TextureManager.h"

using namespace std;

TextureManager* TextureManager::instance = nullptr;
TextureManager * TextureManager::getInstance()
{
	if (TextureManager::instance == 0)
	{
		TextureManager::instance = new TextureManager();
	}

	return TextureManager::instance;
}

sf::Texture TextureManager::getTextureByName(string name)
{
	sf::Texture tmp;
	if (!tmp.loadFromFile(name))
	{
		cout << "Failed to load "<< name <<" spritesheet!" << endl;
		
	}
	return tmp;
}

TextureManager::TextureManager()
{
	if (!playerTexture.loadFromFile("player.png"))
	{
		cout << "Failed to load player spritesheet!" << endl;
		return;
	}
	if (!princessTexture.loadFromFile("princess.png"))
	{
		cout << "Failed to load princess spritesheet!" << endl;
		return;
	}
	
}


TextureManager::~TextureManager()
{
}
