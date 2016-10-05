#include "Bumper.h"



Bumper::Bumper(sf::Vector2f position)
{
	_name = "Bumper";
	_size = sf::Vector2f(200, 20);
	_position = position;
	_bumper.setPosition(_position);
	_bumper.setSize(_size);
	_bumper.setFillColor(sf::Color::Blue);
	_bumper.setOutlineColor(sf::Color::Black);
	_bumper.setOutlineThickness(2);
	_bumper.setOrigin(_bumper.getSize().x /2, _bumper.getSize().y/2);
}


Bumper::~Bumper()
{
}

void Bumper::Events(sf::Event & event)
{
}

void Bumper::Update(sf::Time _deltaTime)
{
	// update ball position
	_position = _bumper.getPosition();


	// move ball
	_bumper.setPosition(sf::Mouse::getPosition(*GetGameWindow()).x, GetGameWindow()->getSize().y - 30);
	// check bumper collision on walls on screen
	if (_bumper.getPosition().x - _size.x /2 <= 0)
	{
		_bumper.setPosition(_size.x / 2, GetGameWindow()->getSize().y - 30);
	}
	if (_bumper.getPosition().x + _size.x / 2 >= 800)
	{
		_bumper.setPosition(800 - _size.x / 2, GetGameWindow()->getSize().y - 30);
	}
}

void Bumper::Render(sf::RenderWindow & _window)
{
	_window.draw(_bumper);
}

