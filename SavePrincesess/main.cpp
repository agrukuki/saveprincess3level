#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <SFML/System.hpp>
#include "Player.h"
#include "Princess.h"
#include "Monster.h"
using namespace std;
#define ROW 10
#define COL 10
char mapLevel0[ROW][COL] = {

{'x','x','x','x','x','x','x','x','x','x'},
{'x','x','w','x','x','x','w','x','x','x'},
{'x','x','x','w','m','x','w','x','x','x'},
{'x','w','w','w','x','x','w','w','x','x'},
{'x','x','x','w','x','m','x','x','m','x'},
{'x','w','x','w','x','w','x','w','x','x'},
{'x','w','x','w','w','w','x','m','x','m'},
{'x','w','x','x','x','x','x','w','m','x'},
{'x','w','x','w','w','x','x','x','x','x'},
{'x','w','x','w','w','x','w','x','x','x'},

};
char mapLevel1[ROW][COL] = {

{ 'x','x','w','w','w','w','w','w','w','w' },
{ 'w','x','w','x','x','x','x','x','x','w' },
{ 'w','x','x','w','m','x','x','x','x','x' },
{ 'w','x','x','x','x','x','x','x','x','w' },
{ 'w','x','x','x','x','x','x','x','x','w' },
{ 'x','x','x','x','x','m','x','x','x','x' },
{ 'w','x','x','x','x','x','x','x','x','w' },
{ 'w','x','x','x','x','x','x','w','x','x' },
{ 'w','x','x','x','x','x','x','x','x','x' },
{ 'w','w','w','w','x','x','w','w','w','x' },

};
char mapLevel2[ROW][COL] = {

{ 'x','x','w','w','w','w','w','w','w','w' },
{ 'w','x','w','x','x','x','x','x','x','w' },
{ 'w','x','w','x','w','w','w','x','x','w' },
{ 'w','x','w','m','x','x','w','x','w','w' },
{ 'w','x','x','x','x','x','x','w','x','w' },
{ 'w','x','w','x','x','x','x','x','x','w' },
{ 'w','x','w','w','x','m','w','x','m','x' },
{ 'w','x','x','x','x','x','w','x','x','x' },
{ 'w','x','x','x','w','m','x','x','x','x' },
{ 'w','w','w','x','w','x','w','w','x','x' },

};
char(*Map)[ROW] = mapLevel0;
enum Direction {LEFT,RIGHT,UP,DOWN};

int level = 0;

Player player(string("Player.png"));
Princess princess(string("Princess.png"));




sf::RenderWindow window(sf::VideoMode(320, 320), "SaveThePrincess!");

sf::RectangleShape shape(sf::Vector2f(320, 320));

sf::Texture monsterTexture;
sf::Texture wallTexture;
vector<sf::Sprite> *wall_vec;
vector<Monster> *monster_vec;

void nextLevel()
{
	//shape.setFillColor(sf::Color::White);
	wall_vec->clear();
	monster_vec->clear();
	princess.setPosition(320 - 32, 320 - 32);

	player.setScale(0.75, 0.75);
	princess.dX = -0.1;


	wallTexture.loadFromFile("wall.jpeg");
	monsterTexture.loadFromFile("slime.png");

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (Map[i][j] == 'w') {
				sf::Sprite wall;
				wall.setPosition(32 * j, 32 * i);
				wall.setTexture(wallTexture);
				wall_vec->push_back(wall);
				cout << "wall at:" << j << "," << i << endl;
			}
				if (Map[i][j] == 'm') {
					Monster monster;
					monster.setTexture(monsterTexture);
					monster.setPosition(32 * j, 32 * i);
					monster_vec->push_back(monster);
				}
			
			
		}
	}
	cout << "wall count :" << wall_vec->size() << " monster count " << monster_vec->size() << endl;

}
int t = 0;
void setup()
{
	shape.setFillColor(sf::Color::White);
	wall_vec = new vector<sf::Sprite>();
	monster_vec = new vector<Monster>();
	princess.setPosition(320 - 32, 320 - 32);
	
	player.setScale(0.75,0.75);
	princess.dX = -0.1;
	
	
	wallTexture.loadFromFile("wall.jpeg");
	monsterTexture.loadFromFile("slime.png");
	
	for (int i = 0; i < ROW;i++) {
		for (int j = 0; j < COL; j++) {
			if (Map[i][j] == 'w') {
				sf::Sprite wall;
				wall.setPosition(32*j, 32*i);
				wall.setTexture(wallTexture);
				wall_vec->push_back(wall);
			}
			if (Map[i][j] == 'm') {
				Monster monster;
				monster.setTexture(monsterTexture);
				monster.setPosition(32 * j ,32 * i);
				monster_vec->push_back(monster);
			}
		}
	}

	cout <<"wall count :" <<wall_vec->size()<< " monster count "<< monster_vec->size() << endl;
	
}
void update()
{
	while (1 == 1)
	{
		t++;
		for (int i = 0; i < wall_vec->size(); i++) {
			if (player.getGlobalBounds().intersects(wall_vec->at(i).getGlobalBounds())) {
				int posX = player.getPosition().x;
				int posY = player.getPosition().y;
				if (posX < wall_vec->at(i).getPosition().x && player.dX > 0)
				player.dX = 0;
				if (posX > wall_vec->at(i).getPosition().x && player.dX < 0)
				player.dX = 0;
				if (posY < wall_vec->at(i).getPosition().y && player.dY > 0)
					player.dY = 0;
				if (posY > wall_vec->at(i).getPosition().y && player.dY < 0)
					player.dY = 0;
			}
		}
		for (int i = 0; i < wall_vec->size(); i++) {
			for (int j = 0; j < monster_vec->size(); j++) {
				if (monster_vec->at(j).getGlobalBounds().intersects(wall_vec->at(i).getGlobalBounds())) {
					int posX = monster_vec->at(j).getPosition().x;
					int posY = monster_vec->at(j).getPosition().y;
					if (posX < wall_vec->at(j).getPosition().x && monster_vec->at(j).dX > 0)
						monster_vec->at(j).dX = -monster_vec->at(j).dX;
					if (posX > wall_vec->at(j).getPosition().x && monster_vec->at(j).dX < 0)
						monster_vec->at(j).dX = -monster_vec->at(j).dX;
					if (posX > wall_vec->at(j).getPosition().y && monster_vec->at(j).dY < 0)
						monster_vec->at(j).dY = -monster_vec->at(j).dY;
					if (posX > wall_vec->at(j).getPosition().y && monster_vec->at(j).dY < 0)
						monster_vec->at(j).dY = -monster_vec->at(j).dY;
				}
			}
		}
		for (int i = 0; i < monster_vec->size(); i++) {
			if (player.getGlobalBounds().intersects(monster_vec->at(i).getGlobalBounds())) {
				if (t > 100) {
					player.die();
					sf::sleep(sf::seconds(2));
					nextLevel();
					
					player.setPosition(0, 0);
					t = 0;
					player.rebirth();
				}
			}
		}

		if (player.getGlobalBounds().intersects(princess.getGlobalBounds()))
		{
			level++;
			if (level == 1) {
				Map = mapLevel1;
				
			}
			if (level == 2) {
				Map = mapLevel2;
			}
			player.setPosition(0, 0);
			nextLevel();
			player.dX = 0;
			player.dY = 0;
			
		}
		princess.update();
		player.update();
		for (int i = 0; i < monster_vec->size();i++) {
			monster_vec->at(i).update();
		}
		sf::sleep(sf::milliseconds(1));
	}
}
sf::Thread thread(&update);




void draw() {
	
	
	window.draw(shape);
	for (int i = 0; i < wall_vec->size();i++) {
		window.draw(wall_vec->at(i));
	}
	for (int i = 0; i < monster_vec->size(); i++) {
		window.draw(monster_vec->at(i));
	}
	
	window.draw(princess);
	window.draw(player);
	
	
	
	
}

int main() {
	// begin
	
	
	
	thread.launch();
	setup();
	
	while (window.isOpen())
	{
		sf::Event event;
		
		
		
				
			
		
		shape.setFillColor(sf::Color::White);
		
		window.clear();
		draw();
		
		while (window.pollEvent(event) )
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::S)
					{
						//player.aX = 0.01;
						player.aY = 0.01;
					}
					if (event.key.code == sf::Keyboard::D)
					{
						player.aX = 0.01;
						//player.aY = 0.01;
					}
					if (event.key.code == sf::Keyboard::A)
					{
						player.aX = -0.01;
						//player.aY = 0.01;
					}
					if (event.key.code == sf::Keyboard::W)
					{
						player.aY = -0.01;
						//player.aY = 0.01;
					}
					if (event.key.code == sf::Keyboard::Up)
						player.dY=-0.25;

					if (event.key.code == sf::Keyboard::Down)
						player.dY = 0.25;

					if (event.key.code == sf::Keyboard::Right)
						player.dX = 0.25;

					if (event.key.code == sf::Keyboard::Left)
						player.dX = -0.25;
					if (event.key.code == sf::Keyboard::X)
						player.die();
				}
				if (event.type == sf::Event::KeyReleased) {
					if (event.key.code == sf::Keyboard::S)
					{
						//player.aX = 0.01;
						player.aY = 0;
						player.dY = 0;
					}
					if (event.key.code == sf::Keyboard::D)
					{
						player.aX = 0;
						//player.aY = 0.01;
						player.dX = 0;
					}
					if (event.key.code == sf::Keyboard::A)
					{
						player.aX = 0;
						//player.aY = 0.01;
						player.dX = 0;
					}
					if (event.key.code == sf::Keyboard::W)
					{
						player.aY = 0;
						player.dY = 0;
						//player.aY = 0.01;
					}
					if (event.key.code == sf::Keyboard::Up)
						player.dY = 0;

					if (event.key.code == sf::Keyboard::Down)
						player.dY = 0;

					if (event.key.code == sf::Keyboard::Right)
						player.dX = 0;

					if (event.key.code == sf::Keyboard::Left)
						player.dX = 0;
				}
			
			

		}
		
		
		
		
		window.display();
		
	}

	return 0;
}
