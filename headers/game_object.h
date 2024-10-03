#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "graphics.h"
#include <stdlib.h>

// Define the GameObject structure
typedef struct {
    Sprite* sprite;      // The object's visual representation
    float x, y;          // Position of the object
    float velocity_x;    // X-axis velocity
    float velocity_y;    // Y-axis velocity
    int width, height;   // Object dimensions
} GameObject;

// Create a new game object with a sprite
GameObject* create_game_object(Sprite* sprite, float x, float y);

// Update the game object's position based on its velocity
void update_game_object(GameObject* object);

// Destroy a game object and free its resources
void destroy_game_object(GameObject* object);

#endif // GAME_OBJECT_H
