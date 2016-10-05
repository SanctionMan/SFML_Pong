#pragma once

#include "Object.h"
#include "Game.h"

class Ball : public Object
{
public:
	Ball(sf::Vector2f position);
	~Ball();

	void Events(sf::Event &event);
	void Update(sf::Time _deltaTime);
	void Render(sf::RenderWindow &_window);

	void CheckScreenCollision();
	void CheckBumperCollision();


private:

	int _size;
	sf::Vector2f _velocity;
	sf::CircleShape _ball;

};

