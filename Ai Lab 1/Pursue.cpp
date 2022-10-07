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


	if (!visionConeTexture.loadFromFile("ASSETS\\IMAGES\\VisionCone.png"))
	{
		std::cout << "error with link image" << std::endl;
	}

	visionConeSprite.setTexture(visionConeTexture);
	visionConeSprite.setOrigin(visionConeSprite.getGlobalBounds().width / 2, 100);
	visionConeSprite.setScale(0.3, 0.3);
	visionConeSprite.setPosition(500, 500);

	pursuePoint.setRadius(20);
	pursuePoint.setFillColor(sf::Color::Blue);

}

void Pursue::draw(sf::RenderWindow& window)
{
	window.draw(visionConeSprite);
	window.draw(pursueSprite);
	window.draw(pursueText);
	window.draw(pursuePoint);
}

void Pursue::update(sf::Time deltaTime, Player t_player)
{
	pursueMovement(deltaTime, t_player);

	pursueText.setPosition(pursueSprite.getPosition().x, pursueSprite.getPosition().y + 100);

	visionConeSprite.setPosition(pursueSprite.getPosition().x, pursueSprite.getPosition().y);
	visionConeSprite.setRotation(pursueSprite.getRotation() + 90);
}

void Pursue::pursueMovement(sf::Time deltaTime, Player t_player)
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

	pursuePoint.setPosition(t_player.getPursueLocation().x, t_player.getPursueLocation().y);
}

void Pursue::spawn()
{
	pursueSprite.setPosition(3840 / 2, 2160 / 2);
}

sf::Sprite Pursue::getVisionCone()
{
	return visionConeSprite;
}
