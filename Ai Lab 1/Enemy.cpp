#include "Enemy.h"

void Enemy::init()
{
	if (!enemyTexture.loadFromFile("ASSETS\\IMAGES\\Octorok.png"))
	{
		std::cout << "error with link image" << std::endl;
	}

	enemySprite.setTexture(enemyTexture);
	enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
	enemySprite.setScale(0.5, 0.5);
	enemySprite.setPosition(500, 500);

	if (!wanderFont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	wanderText.setFont(wanderFont);
	wanderText.setString("Wander");
	wanderText.setCharacterSize(20);
	wanderText.setFillColor(sf::Color::White);
	wanderText.setPosition(100, 100);
	wanderText.setOrigin(wanderText.getGlobalBounds().width / 2, wanderText.getGlobalBounds().height / 2);

	visionCone.setRadius(150);
	visionCone.setPointCount(3);
	visionCone.setFillColor(sf::Color::Red);
	visionCone.setOrigin(150, 75);

	if (!visionConeTexture.loadFromFile("ASSETS\\IMAGES\\VisionCone.png"))
	{
		std::cout << "error with link image" << std::endl;
	}

	visionConeSprite.setTexture(visionConeTexture);
	visionConeSprite.setOrigin(visionConeSprite.getGlobalBounds().width / 2, 100);
	visionConeSprite.setScale(0.3, 0.3);
	visionConeSprite.setPosition(500, 500);

}

void Enemy::draw(sf::RenderWindow& window)
{ 
	window.draw(visionConeSprite);
	window.draw(wanderText);
	window.draw(enemySprite);
}

void Enemy::update(sf::Time deltaTime)
{
	movement(deltaTime);		
	if (enemySprite.getPosition().x > 3840 + 10)
	{
		enemySprite.setPosition(-5, enemySprite.getPosition().y);

	}
	if (enemySprite.getPosition().x < 0 - 10)
	{
		enemySprite.setPosition(3840 + 5, enemySprite.getPosition().y);
	}

	if (enemySprite.getPosition().y > 2160 + 10)
	{
		enemySprite.setPosition(enemySprite.getPosition().x, -5 );

	}
	if (enemySprite.getPosition().y < 0 - 10)
	{
		enemySprite.setPosition(enemySprite.getPosition().x, 2160 + 5);
	}

	wanderText.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y + 100);

	visionConeSprite.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
	visionConeSprite.setRotation(enemySprite.getRotation() + 180);
}

void Enemy::movement(sf::Time deltaTime)
{
	enemyRotateTimer++;
	if (enemyRotateTimer >= 30)
	{
		int randRotation = rand() % 2 + 1;
		if (randRotation == 1)
		{
			rotateLeft = true;
			rotateRight = false;
		}
		else if (randRotation == 2)
		{
			rotateLeft = false;
			rotateRight = true;
		}
		enemyRotateTimer = 0;
	}

	if (rotateLeft == true)
	{
		rotation = rotation - 1;
	}
	else if (rotateRight == true)
	{
		rotation = rotation + 1;
	}
	enemySprite.setRotation(rotation);
	rotation = enemySprite.getRotation();

	xMovement = 2 * sin(rotation * deltaTime.asMilliseconds() / 1000);
	yMovement = 2 * -cos(rotation * deltaTime.asMilliseconds() / 1000);

	float forward = sqrt((xMovement * xMovement) + (yMovement * yMovement));

	sf::Vector2f forwardVel(xMovement, yMovement);
	sf::Vector2f normalizedVel = forwardVel / forward;
	enemySprite.move(normalizedVel);
}

void Enemy::spawn()
{
	enemySprite.setPosition(3840 / 2, 2160 / 2);
}

sf::Sprite Enemy::getVisionCone()
{
	return visionConeSprite;
}
