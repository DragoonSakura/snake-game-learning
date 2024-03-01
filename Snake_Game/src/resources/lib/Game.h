#pragma once
#include <memory>
#include "SDL.h"

// /**
//  * @brief Custom smart pointer for the game window needed by the game class
// */
// class Unique_SDL_Window {
//      private:
     
//      public:
//      Unique_SDL_Window();
//      ~Unique_SDL_Window();
//      Unique_SDL_Window(Unique_SDL_Window& other);
// };

// /**
//  * @brief Custom smart pointer for the game renderer needed by the game class
// */
// class Unique_SDL_Renderer {
//      Unique_SDL_Renderer();
//      ~Unique_SDL_Renderer();
//      Unique_SDL_Renderer(Unique_SDL_Renderer& other);
// };

/**
 * @brief Game window and logic handling class
 * 
 * Game class has a main_windw and main renderer. These are the
 * primary methods of displaying and rendering the game state.
 * 
 * Handle triggers and events within the game logic.
 * Handle the entire game loop.
 * Handle cleanup when game terminates
 * 
*/
class Game {

private:
     bool is_running;
     SDL_Window* main_window;
     SDL_Renderer* main_renderer;

public:

     // Constructor
     Game();
     // Destructor
     ~Game();

     /**
      * @brief Initializes the game class with window specifications
      * 
      * @param title: The name of the window (will be the name of the game)
      * @param xpos: The x coordinate for the center of the window
      * @param ypos: The x coordinate for the center of the window
      * @param width: The width of the window
      * @param height: The height of the window
      * @param screen_size_flag: Flag to set what screen type to run in (windowed, borderless, fullscreen)
     */
     void init(const char* title, int xpos, int ypos, int width, int height, int screen_size_flag);

     /**
      * @brief Checks isRunning to see if the game is still active
      * 
      * @return true if game is running, false if game has terminated
     */
     bool running() const;

     void handleEvents();
     void update();
     void render();

     /**
      * @brief Closes the window and renderer, and shuts down SDL subsystems
     */
     void clean();

};