#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{

public:
	void init();
	void draw(sf::RenderWindow& window);
	void update();
	void movement();

private:
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	int speed = 3;
};

