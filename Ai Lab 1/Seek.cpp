#include "Seek.h"

void Seek::init()
{
	if (!seekTexture.loadFromFile("ASSETS\\IMAGES\\SeekPlane.png"))
	{
		std::cout << "error with link image" << std::endl;
	}

	seekSprite.setTexture(seekTexture);
	seekSprite.setOrigin(seekSprite.getGlobalBounds().width / 2, seekSprite.getGlobalBounds().height / 2);
	seekSprite.setScale(0.5, 0.5);
	seekSprite.setPosition(500, 500);
}

void Seek::draw(sf::RenderWindow& window)
{
	window.draw(seekSprite);
}

void Seek::update(sf::Time deltaTime, Player t_player)
{
	seekMovement(deltaTime, t_player);
}

void Seek::seekMovement(sf::Time deltaTime, Player t_player)
{
	playerPosition = t_player.getSprite().getPosition();
	position = seekSprite.getPosition();

	velocity = playerPosition - position;
	float magnitude = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity = { velocity.x / magnitude, velocity.y / magnitude };
	velocity.x *= MAX_SPEED;
	velocity.y *= MAX_SPEED;

	float dx = position.x - playerPosition.x;
	float dy = position.y - playerPosition.y;
	rotation = (atan2(dy, dx)) * 180 / PI;

	seekSprite.move(velocity);
	seekSprite.setRotation(rotation);
}
