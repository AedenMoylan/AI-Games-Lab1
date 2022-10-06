
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
	sf::Sprite getSprite();
	sf::Vector2f getPursueLocation();

private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	float speed = 0.0f;
	const float SPEED_INCREMENT_VALUE = 0.4f;
	const float MAX_SPEED = 15;
	float xMovement = 0;
	float yMovement = 0;
	float angle = 0;
	float pursueAngle = 0;
	float pursueDistance = 0;
	sf::Vector2f pursuePoint;
	const float PI = 3.141592;

	bool isUpPressed;
	bool isDownPressed;
	bool isLeftPressed;
	bool isRightPressed;
	float turnSpeed = 0.08;
	const float ROTATION_INTENSITY = 10;
};


