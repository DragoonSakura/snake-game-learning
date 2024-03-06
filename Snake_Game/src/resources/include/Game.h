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
     *
     * @return void
    */
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    /**
     * @brief Checks isRunning to see if the game is still active
     *
     * @return true if game is running, false if game has terminated
    */
    bool running() const;

    /*
    * @brief Based on user input and game events, takes appropriate actions.
    *
    * Events occur in the game as a result of game systems resolving
    * or user input.
    * The game must update the game state and progress the game based
    * on the events.
    *
    * @return void
    */
    void handleEvents();

    /*
    * @brief Updates the Game state based on game events.
    *
    * When events are handled by Game::handleEvents, the
    * game state must be changed accordingly so that we
    * can allow the user to interact with the new game
    * state.
    *
    * @return void
    */
    void update();

    /*
    * @brief renders the current game state into the main window
    *
    * After we have handled the game events and updated game state,
    * the new game state must be rendered onto to window for the user
    * to see and further interact with.
    *
    * @return void
    */
    void render();

    /**
     * @brief Closes the window and renderer, and shuts down SDL subsystems
     *
     * @return void
    */
    void clean();

};