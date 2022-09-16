#include "Player.h"

void Player::init()
{
	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\Link.png"))
	{
		std::cout << "error with link image" << std::endl;
	}

	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
	playerSprite.setScale(0.5, 0.5);
	playerSprite.setPosition(800, 800);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
}

void Player::update()
{
	playerMovement();
}

void Player::playerMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		speed += SPEED_INCREMENT_VALUE;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		speed -= SPEED_INCREMENT_VALUE;
	}
	playerSprite.move(speed, 0);
}
