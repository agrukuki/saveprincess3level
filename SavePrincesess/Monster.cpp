#include "Monster.h"



Monster::Monster():Character()
{
	
	int a = rand() % 2;
	if (a == 1)
		this->dX = 0.3;
	if (a == 0)
		this->dY = 0.3;
}


Monster::Monster(sf::Texture texture) : Character(texture)
{
	this->dX = 0.3;
	this->dY = 0.3;
}

void Monster::update()
{
	if (this->getPosition().x>320-32|| this->getPosition().x< 0) {
		this->dX = -this->dX;
	}
	if (this->getPosition().y>320 - 32 || this->getPosition().y< 0) {
		this->dY = -this->dY;
	}
	this->move(this->dX, this->dY);
}

Monster::~Monster()
{
}
