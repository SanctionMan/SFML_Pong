#include "Ball.h"



Ball::Ball(sf::Vector2f position):
	_velocity(300,300)
{
	_name = "Ball";
	_size = 20;
	_position = position;
	_ball.setPosition(_position);
	_ball.setRadius(_size / 2);
	_ball.setFillColor(sf::Color::Red);
	_ball.setOutlineColor(sf::Color::Black);
	_ball.setOutlineThickness(2);
	_ball.setOrigin(_ball.getRadius(), _ball.getRadius());
}


Ball::~Ball()
{
}

void Ball::Events(sf::Event & event)
{
}

void Ball::Update(sf::Time _deltaTime)
{
	// update ball position
	_position = _ball.getPosition();

	// check ball collision
	CheckScreenCollision(); // moved code to function to clean up
	CheckBumperCollision();

	// move ball
	_ball.move(_velocity * _deltaTime.asSeconds());
}

void Ball::Render(sf::RenderWindow & _window)
{
	_window.draw(_ball);
}

void Ball::CheckScreenCollision()
{
	if (_ball.getPosition().x <= 0 + _size)
	{
		_velocity.x *= -1;
	}
	if (_ball.getPosition().x >= 800 - _size)
	{
		_velocity.x *= -1;
	}
	if (_ball.getPosition().y <= 0 + _size)
	{
		_velocity.y *= -1;
	}
	if (_ball.getPosition().y >= 600 - _size)
	{
		_velocity.y *= -1;
	}
}

void Ball::CheckBumperCollision()
{
	// to be added
}
