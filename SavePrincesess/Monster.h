#pragma once
#include "Character.h"
class Monster :
	public Character
{
public:
	Monster();
	Monster(sf::Texture texture);
	void update();
	~Monster();
};

