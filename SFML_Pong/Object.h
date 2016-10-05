#pragma once

#include "SFML\Graphics.hpp"

#include <iostream>

using namespace std;

class Object
{
public:
	Object();
	~Object();

	virtual void Events(sf::Event &event) = 0;
	virtual void Update(sf::Time _deltaTime) = 0;
	virtual void Render(sf::RenderWindow &_window) = 0;

	std::string _name;
	sf::Vector2f _position;
};

