#include "physics.h"
#include <stdio.h>
#include <stdbool.h>

// Stub implementation for applying gravity
void apply_gravity(GameObject* obj, float gravity) {
    // Simulate gravity by printing a message
    printf("Applying gravity (%.2f) to object at position (%.2f, %.2f)\n", gravity, obj->x, obj->y);
    obj->y += gravity;  // Simulate object falling due to gravity
}

// Stub implementation for checking collision between two game objects
bool check_collision(GameObject* obj1, GameObject* obj2) {
    // Print the objects being compared
    printf("Checking collision between objects at positions (%.2f, %.2f) and (%.2f, %.2f)\n",
           obj1->x, obj1->y, obj2->x, obj2->y);
    return false;  // Stub always returns no collision
}
