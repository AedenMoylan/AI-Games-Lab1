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
	randPosX = (rand() % 1000) + 1;
	randPosY = (rand() % 1000) + 1;

	destinationCircle.setFillColor(sf::Color::White);
	destinationCircle.setRadius(3);
	destinationCircle.setOrigin(1.5, 1.5);
	//(rand() % sf::VideoMode::getDesktopMode().width) + 1
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(enemySprite);
	window.draw(destinationCircle);
}

void Enemy::update()
{
	destinationCircle.setPosition(randPosX, randPosY);
	rotationCalculator();		
	movement();
}

void Enemy::movement()
{
	if (enemySprite.getGlobalBounds().intersects(destinationCircle.getGlobalBounds()))
	{
		randomizeWanderLocation();
	}
	
	enemySprite.setPosition(xMovement, yMovement);
}

void Enemy::randomizeWanderLocation()
{
	randPosX = (rand() % sf::VideoMode::getDesktopMode().width) + 1;
	randPosY = (rand() % sf::VideoMode::getDesktopMode().height) + 1;
}

void Enemy::rotationCalculator()
{
	float dx = enemySprite.getPosition().x - randPosX;
	float dy = enemySprite.getPosition().y - randPosY;

	float endRotation = (atan2(dy, dx)) * 180 / 3.14;
	 
	if (rotation < endRotation)
	{
		rotation++;
	}
	if (rotation > endRotation)
	{
		rotation--;
	}

	xMovement += sin(rotation) * 3;
	yMovement -= cos(rotation) * 3;
	enemySprite.setRotation(rotation - 90);
}
