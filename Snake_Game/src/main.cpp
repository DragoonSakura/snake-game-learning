#define SDL_MAIN_HANDLED
#include <iostream>
#include <memory>
#include "GameManager.h"

std::unique_ptr<GameManager> game_manager = nullptr;

int main(int argc, char* args[]) {

	game_manager = std::make_unique<GameManager>();

	game_manager->init();

	game_manager->runGameCycle();

	game_manager->clean();

	return 0;
}