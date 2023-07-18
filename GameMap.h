#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include <iostream>

using namespace sf;
const int HEIGHT_MAP = 25;
const int WIDTH_MAP = 40;
class GameMap {
public:
    
    GameMap(Player& player);
    ~GameMap(); 
    void Load(const std::string& filename);
    void Update(float deltaTime);
    void Render(RenderWindow& window);


private:

    
    

    Sprite s_map;
    RectangleShape rectangle;
    View view;
    CircleShape circle1;
    CircleShape circle2;
    Player &_player;
    Vector2f positionScreen;
    Texture texture;

    sf::String *TileMap;

    friend class MapManager;
};

