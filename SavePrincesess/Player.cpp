#include "Player.h"



Player::Player()
{
}
Player::Player(sf::Texture texture) : Character(texture)
{

}

Player::Player(string name):Character(name)
{
	
}


Player::~Player()
{
}

void Player::update()
{
	this->dX = this->dX + this->aX;
	this->dY = this->dY + this->aY;
	

	this->move(this->dX, this->dY);
	if (this->dX > 0)
		this->right();
	if (this->dX < 0)
		this->left();
	if (this->dY > 0)
		this->down();
	if (this->dY < 0)
		this->up();


}

void Player::rebirth()
{
	this->Alive = true;
	this->setRotation(0);
	this->setOrigin(0, 0);
	this->setColor(sf::Color::White);
}

void Player::down()
{
	if (!this->Alive) return;

	this->setTextureRect(sf::IntRect(32, 0, 32, 32));
}

void Player::up()
{
	if (!this->Alive) return;

	this->setTextureRect(sf::IntRect(32, 96, 32, 32));
}

void Player::left()
{
	if (!this->Alive) return;

	this->setTextureRect(sf::IntRect(32, 32, 32, 32));
}

void Player::right()
{
	if (!this->Alive) return;

	this->setTextureRect(sf::IntRect(32, 64, 32, 32));
}
void Player::die()
{
	if (!this->Alive) return;

	this->Alive = false;
	this->setOrigin(16, 16);
	this->setTextureRect(sf::IntRect(32, 32, 32, 32));
	this->setRotation(90);
	this->setScale(3,3);
	this->setColor(sf::Color::Red);
	return;







}
