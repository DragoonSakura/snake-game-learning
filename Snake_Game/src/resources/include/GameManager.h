#pragma once
#include "Game.h"
// Gets <memory from "Game.h"

/**
 * @ brief Manage Game instance and file handling.
 *
 * GameManager handles the Game class Instance.
 * Abstracts the Game application and game loop.
 * Integrates serialization and file handling.
 * Allows YAML writing and parsing.
*/

class GameManager {

private:
    // Main game instance to be managed
    std::unique_ptr<Game> game;

public:
    /**
     * @brief Construct Game Instance to be initialized later.
     *
     * Sets the unique pointer to the game instance to nullptr as a default.
    */
    GameManager();
    ~GameManager();
    // We want to delete the copy constructor
    // There should only be one game manager per game instance
    GameManager(GameManager& other) = delete;

    /**
     * @build Initializes the Game Manager as well as the game and related entitites.
     *
     * Interacts with launch config YAML to find required launch specification.
     * Creates Game instance using launch specifications for window parameters.
    */
    void init();

    /**
     * @brief Loads the on launch settings saved locally.
     *
     * Loads launch settings to be provided to the GameManager::init method.
     * Allows GameManager::init to load custom user settings from pervious sessions.
    */
    void load_launch_settings();

    /**
     * @brief while game is running, perform a game loop/cycle
     *
     * While the game is running:
     * (1) We handle any new events
     * (2) We update the game state
     * (3) We render the new game state onto the screen
    */
    void runGameCycle();

    /**
     * @brief Shuts down the game and all subsystems
     *
     * Calls the Game::clean() method to close the all game elements.
     * Game::clean() also closes SDL2 subsystems.
    */
    void clean();
};