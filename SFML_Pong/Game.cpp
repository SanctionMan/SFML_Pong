#include "Game.h"

Game* gameHandle = 0; // This is a pointer to our Game object, so we cane access from anywhere

Game::Game()
{
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Window");
	gameHandle = this; // Set gameHandle pointer to this object
}


Game::~Game()
{
	// delete all objects
	DestroyObjects();

	_window->close(); // always close window before we end program
	delete _window; // How we delete our window since we created it on the heap
}

void Game::Run()
{
	// Init Game

	// Create objects
	CreateObject(new Ball(sf::Vector2f(50, 50)));
	CreateObject(new Bumper(sf::Vector2f(_window->getSize().x / 2, _window->getSize().y - 30)));

	// Game Loop
	sf::Clock clock;
	_deltaTime = clock.getElapsedTime();
	while (_window->isOpen())
	{
		_deltaTime += clock.restart();
		while (_deltaTime.asSeconds() >= _frameTime)
		{
			Events(); // Events
			Update(_deltaTime); // Update
			_deltaTime = clock.restart();
		}
		Render(); // Render
	}
}

void Game::Events()
{
	sf::Event event;
	while (_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			_window->close();
			break;
		case sf::Event::Resized:
			break;
		case sf::Event::KeyPressed:
			break;
		case sf::Event::KeyReleased:
			break;
		case sf::Event::MouseButtonPressed:
			break;
		case sf::Event::MouseButtonReleased:
			break;
		case sf::Event::MouseWheelScrolled:
			break;
		}
	}
}

void Game::Update(sf::Time deltaTime)
{
	UpdateObjects();
}

void Game::Render()
{
	// Window Clear
	_window->clear(sf::Color::White);

	// Draw
	RenderObjects();

	// Window Display
	_window->display();
}

void Game::CreateObject(Object* obj)
{
	_objects.push_back(obj);
}

void Game::UpdateObjects()
{
	for (auto &obj : _objects)
	{
		obj->Update(_deltaTime);
	}
}

void Game::RenderObjects()
{
	for (auto &obj : _objects)
	{
		obj->Render(*_window);
	}
}

void Game::DestroyObjects()
{
	for (auto &obj : _objects)
	{
		cout << "Object: " << obj->_name << " Destoryed!" << endl;
		delete obj;
	}
}


sf::RenderWindow* GetGameWindow()
{
	return gameHandle->_window;
}
