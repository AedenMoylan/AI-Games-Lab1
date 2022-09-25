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
	movement();
	destinationCircle.setPosition(randPosX, randPosY);
	rotationCalculator();		
}

void Enemy::movement()
{
	velocity = { randPosX - enemySprite.getPosition().x, randPosY - enemySprite.getPosition().y };
	float magnitude = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity = { velocity.x / magnitude, velocity.y / magnitude };

	enemySprite.move(velocity);

	if (enemySprite.getGlobalBounds().intersects(destinationCircle.getGlobalBounds()))
	{
		randomizeWanderLocation();
	}
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

	float rotation = (atan2(dy, dx)) * 180 / 3.14;

	enemySprite.setRotation(rotation - 90);
}
