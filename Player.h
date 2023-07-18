#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Player{
public:
    Player(float startX = 0.0, float startY=0.0, float playerSpeed=0.0);
    void Update(float deltaTime);
    void Render(RenderWindow& window);
    void Load(const std::string& filename);

    friend class GameMap;
    friend class MapManager;
private:

    Vector2f position;//ѕќ«»÷»я
    Texture texture;
    Sprite sprite;

    int playerScore, health;//нова€ переменна€, хран€ща€ жизни игрока
    bool life;//переменна€ жизнь, логическа€
    float speed;
    int CurrentFrame;
    float runningTime;
    int HeroDirection;//отслеживает кака€ кнопка нажата
 };

