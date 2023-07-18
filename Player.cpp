#pragma once
#include "Player.h"
#include <iostream>

Player::Player(float startX, float startY, float playerSpeed):
    position(startX, startY),
    speed(playerSpeed),
    CurrentFrame(0),
    runningTime(0.0),
    HeroDirection(-1),//отслеживает какая кнопка нажата
    playerScore(0),
    health(100),//новая переменная, хранящая жизни игрока
    life(true)
{
    sprite.setPosition(position);
}


void Player::Update(float deltaTime) {

    if (life = true) {
        float distance = speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            HeroDirection = 1;
            runningTime += deltaTime;
            if (runningTime >= 0.1) {
                CurrentFrame = (CurrentFrame + 1) % 4;
                runningTime = 0.0;
            }
            sprite.setTextureRect(sf::IntRect(int(CurrentFrame) * 64, 192, 64, 96));
            position.x += distance;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            HeroDirection = 2;
            runningTime += deltaTime;
            if (runningTime >= 0.1) {
                CurrentFrame = (CurrentFrame + 1) % 4;
                runningTime = 0.0;
            }
            sprite.setTextureRect(sf::IntRect(int(CurrentFrame) * 64, 288, 64, 96));
            position.y -= distance;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            HeroDirection = 3;
            runningTime += deltaTime;
            if (runningTime >= 0.1) {
                CurrentFrame = (CurrentFrame + 1) % 4;
                runningTime = 0.0;
            }
            sprite.setTextureRect(sf::IntRect(int(CurrentFrame) * 64, 0, 64, 96));
            position.y += distance;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            HeroDirection = 0;
            runningTime += deltaTime;
            if (runningTime >= 0.1) {
                CurrentFrame = (CurrentFrame + 1) % 4;
                runningTime = 0.0;
            }
            sprite.setTextureRect(sf::IntRect(int(CurrentFrame) * 64, 96, 64, 96));
            position.x -= distance;
        }
        sprite.setPosition(position);
    }
}

void Player::Render(sf::RenderWindow& window) {
    /*sf::IntRect textureRect(, 100, 100);
    sprite.setTextureRect(textureRect);*/
    window.draw(sprite);
}

void Player::Load(const std::string& filename) {
    if (texture.loadFromFile(filename)) {
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 64, 96));
    }
}