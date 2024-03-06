#include <iostream>
#include "Game.h"


Game::Game()
    :is_running(false), main_window(nullptr), main_renderer(nullptr)
{}

Game::~Game() { clean(); }

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

    // WHen the Game class is initialized the game is considered to be active
    is_running = true;

    // Activate SDL subsystems
    // Confirm subsystems activated via bool operator
    // If successful create main game window and renderer
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL2 subsystems initialized." << std::endl;
        main_window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
        if (main_window) { std::cout << "Window created." << std::endl; }
        main_renderer = SDL_CreateRenderer(main_window, -1, 0);
    }

    // Set render Background Color ONLY IF renderer initialized successfully
    if (main_renderer) {
        std::cout << "Renderer created." << std::endl;
        SDL_SetRenderDrawColor(main_renderer, 255, 190, 120, 255);
    }

    // Safety case, if anything fails shut down the game
    else { is_running = false; }
}

// ————————————————————————————————————————————————————————————————————————————————————————————————————

bool Game::running() const {

    return is_running;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        is_running = false;
        break;

    default:
        break;
    }
}

void Game::update() {
}

void Game::render() {
    SDL_RenderClear(main_renderer);
    SDL_RenderPresent(main_renderer);

}

// ————————————————————————————————————————————————————————————————————————————————————————————————————

void Game::clean() {

    // Close game window, renderer and subsystems
    SDL_DestroyWindow(main_window);
    std::cout << "Window closed." << std::endl;
    SDL_DestroyRenderer(main_renderer);
    std::cout << "Renderer closed." << std::endl;
    SDL_Quit();
    std::cout << "SDL2 shutdown." << std::endl;
    std::cout << "Game shutting down." << std::endl;
}