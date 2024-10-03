#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include <SDL2/SDL.h> // Include SDL header

typedef struct {
    uint8_t* pixels;  // Pointer to pixel data
    int width;
    int height;
} Sprite;

// Declare extern variables
extern SDL_Window* window;
extern SDL_Renderer* renderer;

// Function declarations...
void init_graphics();
void set_background_color(uint8_t r, uint8_t g, uint8_t b);
void draw_pixel(int x, int y, uint8_t color);
void draw_sprite(Sprite* sprite, int x, int y);
Sprite* load_bmp_sprite(const char* filename);

#endif // GRAPHICS_H
