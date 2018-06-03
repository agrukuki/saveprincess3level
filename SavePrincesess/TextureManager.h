#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
class TextureManager
{
	static TextureManager* instance ;
	
public:
	sf::Texture playerTexture;
	sf::Texture princessTexture;
	static TextureManager* getInstance();
	sf::Texture getTextureByName(string name);
	
	private:
		TextureManager();
	~TextureManager();
};

