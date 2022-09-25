
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	void init();
	void draw(sf::RenderWindow& window);
	void update();
	void playerMovement();
private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	float speed = 4.0f;
	const float SPEED_INCREMENT_VALUE = 0.4f;
};


