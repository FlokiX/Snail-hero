#include "Player.h"
#include "Game.h"
#include <iostream>

using namespace sf;

Game::Game(int windowZizeX, int windowZizeY) : window(sf::VideoMode(windowZizeX, windowZizeY), "SFML Game"),
    isRunning(false),
    player(400,400, 150),
    totalTime(0.0),
    gameMap(player),
    mapManager(gameMap, player),
    _windowZizeX(windowZizeX),
    _windowZizeY(windowZizeY)
{}

void Game::Run() {
    Initialize();
    isRunning = true;

    while (isRunning) {
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();
        //std::cout << " deltaTime : " << dt << " seconds" << std::endl;
    
        ProcessEvents();
        Update(dt); 
        Render();
    }
}

void Game::Initialize() {
    // Инициализация игровых компонентов

    window.setFramerateLimit(60);
    gameMap.Load("Texture/map2.png");
    background.Load("Texture/background.png");
    player.Load("Texture/Player.png");
}


void Game::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            isRunning = false;
    }
}

void Game::Update(float dt){
    gameMap.Update(dt);
    player.Update(dt);
    mapManager.Update(dt);
}

void Game::Render() {
    window.clear();

    //background.Render(window);
    gameMap.Render(window);
    mapManager.Render(window);
   
    window.display();
}