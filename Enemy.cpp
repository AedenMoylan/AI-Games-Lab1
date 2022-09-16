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

void Enemy::update()
{
	movement();
}

void Enemy::movement()
{
	enemySprite.move(speed, 0);
}
