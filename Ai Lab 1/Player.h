
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
	float speed = 0.0f;
	const float SPEED_INCREMENT_VALUE = 0.4f;
	const float MAX_SPEED = 15;
	float xMovement = 0;
	float yMovement = 0;
	float angle = 0;

	bool isUpPressed;
	bool isDownPressed;
	bool isLeftPressed;
	bool isRightPressed;
	float turnSpeed = 0.08;
	const float ROTATION_INTENSITY = 10;
};


