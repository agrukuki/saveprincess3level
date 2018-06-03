#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player(sf::Texture texture);
	Player(string name);
	float aX = 0;
	float aY = 0;

	void update();
	void rebirth();
	void down();
	void up();
	void left();
	void right();
	void die();
	Player();
	~Player();
};

