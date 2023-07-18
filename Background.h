#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Background {
public:
    Background();

    void Load(const std::string& filename);
    void Render(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

