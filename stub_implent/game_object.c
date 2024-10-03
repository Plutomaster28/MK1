#include "game_object.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new game object with a sprite
GameObject* create_game_object(Sprite* sprite, float x, float y) {
    GameObject* object = malloc(sizeof(GameObject));
    if (!object) {
        return NULL; // Check for successful memory allocation
    }
    object->sprite = sprite;
    object->x = x;
    object->y = y;
    object->velocity_x = 0; // Initialize velocity to 0
    object->velocity_y = 0; // Initialize velocity to 0
    object->width = sprite->width;  // Assuming Sprite has a width property
    object->height = sprite->height; // Assuming Sprite has a height property
    return object;
}

// Update the game object's position based on its velocity
void update_game_object(GameObject* object) {
    if (object) {
        object->x += object->velocity_x; // Update position
        object->y += object->velocity_y; // Update position
    }
}

// Destroy a game object and free its resources
void destroy_game_object(GameObject* object) {
    if (object) {
        free(object);
    }
}
