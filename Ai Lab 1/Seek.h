#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "Player.h"

class Seek
{
public:
	void init();
	void draw(sf::RenderWindow& window);
	void update(sf::Time deltaTime, Player t_player);
	void seekMovement(sf::Time deltaTime, Player t_player);
	void spawn();
	sf::Sprite getVisionCone();
	sf::Sprite visionConeSprite;
private:
	sf::Texture seekTexture;
	sf::Sprite seekSprite;
	sf::Font seekFont;
	sf::Text seekText;

	sf::Texture visionConeTexture;

	sf::Vector2f playerPosition;
	sf::Vector2f position;
	sf::Vector2f velocity;
	const float PI = 3.141592;
	const int MAX_SPEED = 3;
	float rotation;



};

