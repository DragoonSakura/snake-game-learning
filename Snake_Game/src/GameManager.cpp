#include "Cardinal_Data_Manager.h"
#include "GameManager.h"
// Gets <memory from "GameManager.h"


GameManager::GameManager()
     :game(nullptr)
     {}

GameManager::~GameManager() {}

// We only want one game manager per game instance
GameManager::GameManager(GameManager& other) = delete;

// ————————————————————————————————————————————————————————————————————————————————————————————————————

void GameManager::init() {}

void load_launch_settings();

void GameManager::runGameCycle() {
     while (game->running()) {
          game->handleEvents();
          game->update();
          game->render();
     }
}

void GameManager::clean() {
	
	// Close all processes when the game closes
	game->clean();
}