#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "Player.h"

class Pursue
{
public:
	void init();
	void draw(sf::RenderWindow& window);
	void update(sf::Time deltaTime, Player t_player);
	void pursueMovement(sf::Time deltaTime, Player t_player);
	void spawn();
	sf::Sprite getVisionCone();
	sf::Sprite visionConeSprite;

private:
	sf::Sprite pursueSprite;
	sf::Texture pursueTexture;
	sf::Font pursueFont;
	sf::Text pursueText;
	sf::CircleShape pursuePoint;

	sf::Vector2f playerPosition;
	sf::Vector2f position;
	sf::Vector2f velocity;
	const float PI = 3.141592;
	const int MAX_SPEED = 10;
	float rotation;

	sf::Texture visionConeTexture;


};

