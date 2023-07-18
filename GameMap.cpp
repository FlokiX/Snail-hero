#include "GameMap.h"


GameMap::GameMap(Player& player) : _player(player){

    view = sf::View(sf::FloatRect(0, 0, 800, 600)); // ѕример размеров окна

    rectangle.setSize(sf::Vector2f(200, 100));
    rectangle.setPosition(400,250);
    rectangle.setFillColor(sf::Color::Red);

    circle1.setRadius(50.f);
    circle1.setFillColor(sf::Color::Red);
    circle1.setPosition(400, 50);

    circle2.setRadius(50.f);
    circle2.setFillColor(sf::Color::Blue);
    circle2.setPosition(200,50);
}
GameMap::~GameMap() {
    delete[] TileMap;
}
void GameMap::Load(const std::string& filename) {

    if (texture.loadFromFile(filename)) {
        s_map.setTexture(texture); // ѕредполагаетс€, что вы уже загрузили текстуру
        s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
    }
   
  
    TileMap = new sf::String[HEIGHT_MAP]
    {
        "0000000000000000000000000000000000000000",
        "0       s                              0",
        "0   s                                  0",
        "0     s   s                            0",
        "0  s                                   0",
        "0                                      0",
        "0   s     s                            0",
        "0                    h                 0",
        "0                                      0",
        "0                                      0",
        "0                          h           0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                           f          0",
        "0             f                        0",
        "0                                      0",
        "0                                      0",
        "0                            f         0",
        "0                                      0",
        "0                                      0",
        "0        f                             0",
        "0                                      0",
        "0000000000000000000000000000000000000000",
    };
 }






void GameMap::Update(float deltaTime) {

    positionScreen.x = _player.sprite.getPosition().x + 64 - (800 / 2);
    positionScreen.y = _player.sprite.getPosition().y + 96 - (600 / 2);

    if (positionScreen.x < 0)
        positionScreen.x = 0;

    if (positionScreen.y < 0)
        positionScreen.y = 0;

    view.reset(sf::FloatRect(positionScreen.x, positionScreen.y, 800, 600));

    if (_player.health <= 0) { _player.life = false; _player.speed = 0; }//если жизней меньше либо равно 0, то умираем и исключаем движение игрока после смерти
}

void GameMap::Render(sf::RenderWindow& window) {
    for (int i = 0; i < HEIGHT_MAP; i++) {
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
            if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
            if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
            if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));//добавили цветок
            if ((TileMap[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));//и сердечко
             
            if (TileMap[i][j] == 'f') {
                _player.health -= 40;//если вз€ли €довитейший в мире цветок,то переменна€ health=health-40;
                TileMap[i][j] = ' ';//убрали цветок
            }

            if (TileMap[i][j] == 'h') {
                _player.health += 20;//если вз€ли сердечко,то переменна€ health=health+20;
                TileMap[i][j] = ' ';//убрали сердечко
            }

            s_map.setPosition(j * 32, i * 32);
            window.draw(s_map);
        }
    }
    window.setView(view);
    //window.draw(rectangle);
    //window.draw(circle1);
    //window.draw(circle2);
}