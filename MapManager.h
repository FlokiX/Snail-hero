#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameMap.h"


class MapManager {
public:
    MapManager(GameMap& gameMap, Player& player);
    void Update(float deltaTime);
    void Render(sf::RenderWindow& window);

private:
   
    sf::FloatRect playerBouds;
    sf::FloatRect objectBouds;

    GameMap& _GameMap;
    Player& _player;  
};

