#include "GameManager.h"
// Gets <memory from "GameManager.cpp"

std::unique_ptr<GameManager> game_manager = nullptr;

int main(int argc, char* args[]) {

     game_manager = std::make_unique<GameManager>();
     
     game_manager->init();
     
     game_manager->runGameCycle();
}