#pragma once

#include "Object.h"
#include "Game.h"

class Bumper : public Object
{
public:
	Bumper(sf::Vector2f position);
	~Bumper();

	void Events(sf::Event &event);
	void Update(sf::Time _deltaTime);
	void Render(sf::RenderWindow &_window);


private:

	sf::Vector2f _size;
	sf::RectangleShape _bumper;
};

