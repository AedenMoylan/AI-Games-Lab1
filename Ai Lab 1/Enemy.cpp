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
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(enemySprite);
}

void Enemy::update(sf::Time deltaTime)
{
	movement(deltaTime);		
	if (enemySprite.getPosition().x < -50)
	{
		enemySprite.setPosition(2600, enemySprite.getPosition().y);
	}
	else if (enemySprite.getPosition().x > 2500)
	{
		enemySprite.setPosition(-49, enemySprite.getPosition().y);
	}
	else if (enemySprite.getPosition().y < -50)
	{
		enemySprite.setPosition(enemySprite.getPosition().x, 1500);
	}
	else if (enemySprite.getPosition().y > 1501)
	{
		enemySprite.setPosition(-enemySprite.getPosition().x, -49);
	}
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