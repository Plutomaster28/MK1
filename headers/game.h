#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

typedef struct {
    int width;
    int height;
    char* title;
    bool running;
} Game;

// Initialize the game window and resources
Game* create_game(int width, int height, const char* title);

// Start the game loop
bool game_is_running(Game* game);

// Close the game and free resources
void destroy_game(Game* game);

// Set the background color (RGB values between 0-255)
void set_background_color(int r, int g, int b);

// Render all game objects and update the display
void render_game(Game* game);

#endif // GAME_H
