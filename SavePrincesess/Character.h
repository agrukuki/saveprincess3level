#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "TextureManager.h"
#include <string>
using namespace std;
class Character : public sf::Sprite
{
protected:	
	bool Alive = true;
	string name;
	sf::Texture myTexture;
public:
	
	
	float dX = 0;
	float dY = 0;
	void update();
	
	void down();
	void up();
	void left();
	void right();
	void die();
	

	Character(string name);
	Character(sf::Texture texture);
	Character();
	~Character();
};

