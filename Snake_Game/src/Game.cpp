#include "Game.h"


Game::Game()
     :is_running(false), main_window(nullptr), main_renderer(nullptr)
{}

Game::~Game() { clean(); }

void Game::init(const char* title, int xpos, int ypos, int width, int height, int window_size_flag) {

     // WHen the Game class is initialized the game is considered to be active
     is_running = true;
     // For window creation, is decided later based on config setting
     int window_flags = 0;
     // To easily check which window size config flag was passed in
     enum screen_size_setting {fullscreen, borderless, windowed};

     if(window_size_flag == fullscreen) { window_flags = SDL_WINDOW_FULLSCREEN; }
     else if (window_size_flag == borderless) { window_flags = SDL_WINDOW_BORDERLESS; }

     // Activate SDL subsystems
     // Confirm subsystems activated via bool operator
     // If successful create main game window and renderer
     if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
          main_window = SDL_CreateWindow(title, xpos, ypos, width, height, window_flags);
          main_renderer = SDL_CreateRenderer(main_window, -1, 0);
     }

     // Set render Background Color ONLY IF renderer initialized successfully
     if (main_renderer) {
          SDL_SetRenderDrawColor(main_renderer, 255, 190, 120, 255);
     }

     // Safety case, if anything fails shut down the game
     else {is_running = false;}
}

// ————————————————————————————————————————————————————————————————————————————————————————————————————

bool Game::running() const {

	return is_running;
}

void Game::handleEvents() {

}

void Game::update() {
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

// ————————————————————————————————————————————————————————————————————————————————————————————————————

void Game::clean() {

     // Close game window, renderer and subsystems
     SDL_DestroyWindow(main_window);
     SDL_DestroyRenderer(main_renderer);
     SDL_Quit();
}