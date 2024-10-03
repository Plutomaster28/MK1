#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

SDL_Window* window = NULL; // Define the window variable
SDL_Renderer* renderer = NULL; // Define the renderer variable

void init_graphics() {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void set_background_color(uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
}

void draw_pixel(int x, int y, uint8_t color) {
    SDL_SetRenderDrawColor(renderer, color, color, color, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

Sprite* load_bmp_sprite(const char* filename) {
    SDL_Surface* surface = SDL_LoadBMP(filename);
    if (!surface) {
        printf("Failed to load BMP: %s\n", SDL_GetError());
        return NULL;
    }

    Sprite* sprite = malloc(sizeof(Sprite));
    sprite->width = surface->w;
    sprite->height = surface->h;
    sprite->pixels = surface->pixels;

    SDL_FreeSurface(surface);
    return sprite;
}

void draw_sprite(Sprite* sprite, int x, int y) {
    // Draw the sprite (stub)
    SDL_Rect rect = { x, y, sprite->width, sprite->height };
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, (SDL_Surface*)sprite->pixels);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}
