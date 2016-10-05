#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include "Object.h"
#include "Ball.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Events();
	void Update(sf::Time deltaTime);
	void Render();

	void CreateObject(Object* obj);
	void UpdateObjects();
	void RenderObjects();
	void DestroyObjects();

	sf::RenderWindow* _window;
	std::vector<Object*> _objects;

private:

	// Time
	float _frameTime = 0.1f / 60.0f;
	sf::Time _deltaTime;

};

// How to get game window from anywhere
sf::RenderWindow* GetGameWindow();

