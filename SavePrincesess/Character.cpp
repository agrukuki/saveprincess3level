#include "Character.h"


void Character::update()
{
	
	this->move(this->dX, this->dY);
	
	

}

void Character::down()
{
	
}

void Character::up()
{
	
}

void Character::left()
{
	
}

void Character::right()
{
	
}
void Character::die()
{
	

}


Character::Character() : sf::Sprite()
{
	
	
	
		

	
}
Character::Character(string name) : sf::Sprite()
{

	
	if (!myTexture.loadFromFile(name))
	{
		cout << "Failed to load " << name << " spritesheet!" << endl;

	}
	this->setTexture(myTexture);
	this->setTextureRect(sf::IntRect(0, 0, 32, 32));
	/*this->setTexture(TextureManager::getInstance()->getTextureByName(name));
	this->setTextureRect(sf::IntRect(32, 0, 32, 32));*/


}

Character::Character(sf::Texture texture) : sf::Sprite(texture)
{

}



Character::~Character()
{
}
