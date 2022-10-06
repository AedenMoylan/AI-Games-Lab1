#include "Arrive.h"

void Arrive::init()
{
	if (!arriveTexture.loadFromFile("ASSETS\\IMAGES\\ArrivePlane.png"))
	{
		std::cout << "error with link image" << std::endl;
	}
	if (!arriveFont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	for (int i = 0; i < MAX_ARRIVE_ENEMIES; i++)
	{

		arriveSprite[i].setTexture(arriveTexture);
		arriveSprite[i].setOrigin(arriveSprite[i].getGlobalBounds().width / 2, arriveSprite[i].getGlobalBounds().height / 2);
		arriveSprite[i].setScale(0.3, 0.3);
		arriveSprite[i].setPosition(500 * i, 500 * i);

		arriveText[i].setFont(arriveFont);
		if (i == 0)
		{		
			arriveText[i].setString("Slow Arrive");
		}
		else
		{
			arriveText[i].setString("Fast Arrive");
		}
		arriveText[i].setCharacterSize(20);
		arriveText[i].setFillColor(sf::Color::White);
		arriveText[i].setPosition(100, 100);
		arriveText[i].setOrigin(arriveText[i].getGlobalBounds().width / 2, arriveText[i].getGlobalBounds().height / 2);
	}
}

void Arrive::draw(sf::RenderWindow& window, bool canSlowArriveBeDrawn, bool canFastArriveBeDrawn)
{

	for (int i = 0; i < MAX_ARRIVE_ENEMIES; i++)
	{
		if (canSlowArriveBeDrawn == true)
		{
			window.draw(arriveSprite[0]);
			window.draw(arriveText[0]);
		}
		if (canFastArriveBeDrawn == true)
		{
			window.draw(arriveSprite[1]);
			window.draw(arriveText[1]);
		}
	}
}

void Arrive::update(sf::Time deltaTime, Player t_player)
{
	arriveMovement(deltaTime, t_player);

	for (int i = 0; i < MAX_ARRIVE_ENEMIES; i++)
	{
		arriveText[i].setPosition(arriveSprite[i].getPosition().x, arriveSprite[i].getPosition().y + 100);
	}
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

void Arrive::spawnSlow()
{
	arriveSprite[0].setPosition(1000, 800);
}

void Arrive::spawnFast()
{
	arriveSprite[1].setPosition(1000, 800);
}

