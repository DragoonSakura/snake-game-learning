#include <iostream>
#include "GameManager.h"

GameManager::GameManager()
    :game(nullptr)
{}

GameManager::~GameManager() {}

// We only want one game manager per game instance
// So copy constructor is deleted in GameManager.h

// ——————————————————————————————————————————————————

void GameManager::init() {
    game = std::make_unique<Game>();
    game->init("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
}

void GameManager::load_launch_settings() {}

void GameManager::runGameCycle() {
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }
}

// ——————————————————————————————————————————————————

void GameManager::clean() {

    // Close all processes when the game closes
    game->clean();
    std::cout << "Game shutdown." << std::endl;
    std::cout << "Snake Game closing." << std::endl;
}