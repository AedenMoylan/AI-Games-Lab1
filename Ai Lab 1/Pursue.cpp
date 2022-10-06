#include "Pursue.h"

void Pursue::init()
{
	if (!pursueTexture.loadFromFile("ASSETS\\IMAGES\\PursuePlane.png"))
	{
		std::cout << "error with link image" << std::endl;
	}

	pursueSprite.setTexture(pursueTexture);
	pursueSprite.setOrigin(pursueSprite.getGlobalBounds().width / 2, pursueSprite.getGlobalBounds().height / 2);
	pursueSprite.setScale(0.4, 0.4);
	pursueSprite.setPosition(500, 500);

	if (!pursueFont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	pursueText.setFont(pursueFont);
	pursueText.setString("Pursue");
	pursueText.setCharacterSize(20);
	pursueText.setFillColor(sf::Color::White);
	pursueText.setPosition(100, 100);
	pursueText.setOrigin(pursueText.getGlobalBounds().width / 2, pursueText.getGlobalBounds().height / 2);
}

void Pursue::draw(sf::RenderWindow& window)
{
	window.draw(pursueSprite);
	window.draw(pursueText);
}

void Pursue::update(sf::Time deltaTime, Player t_player)
{
	seekMovement(deltaTime, t_player);

	pursueText.setPosition(pursueSprite.getPosition().x, pursueSprite.getPosition().y + 100);
}

void Pursue::seekMovement(sf::Time deltaTime, Player t_player)
{
	playerPosition.x = t_player.getPursueLocation().x;
	playerPosition.y = t_player.getPursueLocation().y;
	position = pursueSprite.getPosition();

	velocity = playerPosition - position;
	float magnitude = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity = { velocity.x / magnitude, velocity.y / magnitude };
	velocity.x *= MAX_SPEED;
	velocity.y *= MAX_SPEED;

	float dx = position.x - playerPosition.x;
	float dy = position.y - playerPosition.y;
	rotation = (atan2(dy, dx)) * 180 / PI;

	pursueSprite.move(velocity);
	pursueSprite.setRotation(rotation);
}

void Pursue::spawn()
{
	pursueSprite.setPosition(1000, 800);
}
