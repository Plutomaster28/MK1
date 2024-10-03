#include "game.h"
#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} Game;

Game* create_game(int width, int height, const char* title) {
    Game* game = malloc(sizeof(Game));
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Init Error: %s\n", SDL_GetError());
        return NULL;
    }
    
    game->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!game->window) {
        printf("SDL Window Error: %s\n", SDL_GetError());
        return NULL;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (!game->renderer) {
        printf("SDL Renderer Error: %s\n", SDL_GetError());
        return NULL;
    }

    return game;
}

void destroy_game(Game* game) {
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}

int game_is_running(Game* game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return 0;
        }
    }
    return 1;
}

void set_background_color(int r, int g, int b) {
    SDL_SetRenderDrawColor(SDL_GetRenderer(SDL_GetWindowFromID(1)), r, g, b, 255);
}

void render_game(Game* game) {
    SDL_RenderClear(game->renderer);
    SDL_RenderPresent(game->renderer);
}
