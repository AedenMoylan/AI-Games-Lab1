#include "Player.h"

void Player::init()
{
	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\Player.png"))
	{
		std::cout << "error with link image" << std::endl;
	}

	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
	playerSprite.setScale(0.25, 0.25);
	playerSprite.setPosition(800, 800);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
}

void Player::update()
{
	playerMovement();
	playerSprite.setPosition(xMovement, yMovement);
	playerSprite.setRotation(angle * 180 / 3.14);
	boundaryCheck();

}

void Player::playerMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && speed < MAX_SPEED)
	{
		speed += SPEED_INCREMENT_VALUE;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && speed > (MAX_SPEED * -1))
	{
		speed -= SPEED_INCREMENT_VALUE;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (speed != 0)
		{
			angle += turnSpeed * speed / ROTATION_INTENSITY;
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (isLeftPressed && speed != 0)
		{
			angle -= turnSpeed * speed / ROTATION_INTENSITY;
		}
	}

	xMovement += sin(angle) * speed;
	yMovement -= cos(angle) * speed;

	pursueDistance = speed * 25;
	pursuePoint.x = playerSprite.getPosition().x + pursueDistance * cos(angle + 67.5);
	pursuePoint.y = playerSprite.getPosition().y + pursueDistance * sin(angle + 67.5);
}

sf::Sprite Player::getSprite()
{
	return playerSprite;
}

sf::Vector2f Player::getPursueLocation()
{
	return pursuePoint;
}

void Player::boundaryCheck()
{
	if (playerSprite.getPosition().x > 3840 + 10)
	{
		xMovement = -5;

	}
	if (playerSprite.getPosition().x < 0 - 10)
	{
		xMovement = 3840 + 5;
	}

	if (playerSprite.getPosition().y > 2160 + 10)
	{
		yMovement = -5;

	}
	if (playerSprite.getPosition().y < 0 - 10)
	{
		yMovement = 2160 + 5;
	}
}

