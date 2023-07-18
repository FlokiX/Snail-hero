#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "GameMap.h"
#include "MapManager.h"

using namespace sf;

class Game {
public:
    Game(int windowZizeX, int windowZizeY);
    void Run();

private:
    bool isRunning;

    RenderWindow window;
    Player player;
    Background background;
    GameMap gameMap;    
    MapManager mapManager;
    Clock clock;

    float totalTime;
    int _windowZizeX;
    int _windowZizeY;

    void Initialize();
    void ProcessEvents();
    void Update(float deltaTime);
    void Render();
};

