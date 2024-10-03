#ifndef PHYSICS_H
#define PHYSICS_H

#include "game_object.h"
#include <stdbool.h>

// Apply gravity to a game object
void apply_gravity(GameObject* obj, float gravity);

// Check for collision between two game objects
bool check_collision(GameObject* obj1, GameObject* obj2);

#endif // PHYSICS_H

