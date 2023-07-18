#include "Background.h"

Background::Background() {
}

void Background::Load(const std::string& filename) {
    if (texture.loadFromFile(filename)) {
        sprite.setTexture(texture);
    }
}

void Background::Render(sf::RenderWindow& window) {
    window.draw(sprite);
}