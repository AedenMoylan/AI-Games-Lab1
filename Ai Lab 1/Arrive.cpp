#include "Arrive.h"

void Arrive::init()
{
	if (!arriveTexture.loadFromFile("ASSETS\\IMAGES\\ArrivePlane.png"))
	{
		std::cout << "error with link image" << std::endl;
	}

	for (int i = 0; i < MAX_ARRIVE_ENEMIES; i++)
	{

		arriveSprite[i].setTexture(arriveTexture);
		arriveSprite[i].setOrigin(arriveSprite[i].getGlobalBounds().width / 2, arriveSprite[i].getGlobalBounds().height / 2);
		arriveSprite[i].setScale(0.3, 0.3);
		arriveSprite[i].setPosition(500 * i, 500 * i);
	}
}

void Arrive::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_ARRIVE_ENEMIES; i++)
	{
		window.draw(arriveSprite[i]);
	}
}

void Arrive::update(sf::Time deltaTime, Player t_player)
{
	arriveMovement(deltaTime, t_player);
}

void Arrive::arriveMovement(sf::Time deltaTime, Player t_player)
{
	for (int i = 0; i < MAX_ARRIVE_ENEMIES; i++)
	{
		playerPosition = t_player.getSprite().getPosition();
		position = arriveSprite[i].getPosition();

		velocity = playerPosition - position;
		float magnitude = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
		velocity = { velocity.x / magnitude, velocity.y / magnitude };
		
		if (i == 0)
		{
			velocity.x *= MAX_SPEED_SLOW;
			velocity.y *= MAX_SPEED_SLOW;
		}
		else
		{
			velocity.x *= MAX_SPEED_FAST;
			velocity.y *= MAX_SPEED_FAST;
		}

		float dx = position.x - playerPosition.x;
		float dy = position.y - playerPosition.y;
		rotation = (atan2(dy, dx)) * 180 / PI;

		if (magnitude <= radius)
		{
			float slowDownAmount = magnitude / 200;
			velocity.x *= slowDownAmount;
			velocity.y *= slowDownAmount;
		}
		if (magnitude <= radius * 0.1)
		{
			velocity = { 0,0 };
		}
		arriveSprite[i].move(velocity);
		arriveSprite[i].setRotation(rotation);
	}
}
