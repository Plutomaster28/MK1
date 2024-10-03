#include <windows.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Struct to represent a game object
typedef struct {
    float x, y; // Position
    float velocity_x, velocity_y; // Movement speed
    SDL_Texture *texture; // Texture for the sprite
} GameObject;

// Function to initialize SDL
int init_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    return 0;
}

// Function to create a window and renderer
int create_window_and_renderer(SDL_Window **window, SDL_Renderer **renderer) {
    *window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!*window) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (!*renderer) {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(*window);
        return -1;
    }
    return 0;
}

// Function to load background music
int load_music(const char *filename, Mix_Music **music) {
    *music = Mix_LoadMUS(filename);
    if (!*music) {
        fprintf(stderr, "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
        return -1;
    }
    return 0;
}

// Function to load a sprite
SDL_Texture* load_sprite(SDL_Renderer *renderer, const char *filename) {
    SDL_Surface *surface = SDL_LoadBMP(filename);
    if (!surface) {
        fprintf(stderr, "Failed to load sprite! SDL_Error: %s\n", SDL_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

// Function to handle player movement
void handle_input(GameObject *player) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    player->velocity_x = 0;
    player->velocity_y = 0;

    if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) { // Move up
        player->velocity_y = -1.0f;
    }
    if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]) { // Move down
        player->velocity_y = 1.0f;
    }
    if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) { // Move left
        player->velocity_x = -1.0f;
    }
    if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) { // Move right
        player->velocity_x = 1.0f;
    }

    // Update player position
    player->x += player->velocity_x;
    player->y += player->velocity_y;
}

// Main entry point of the application
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    Mix_Music *music = NULL;

    // Initialize SDL
    if (init_sdl() < 0) {
        return 1;
    }

    // Create window and renderer
    if (create_window_and_renderer(&window, &renderer) < 0) {
        SDL_Quit();
        return 1;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf(stderr, "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load and play background music
    if (load_music("MK1_N168_TEST.mp3", &music) < 0) {
        Mix_CloseAudio();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    Mix_PlayMusic(music, -1); // -1 means loop indefinitely

    // Create a game object for the player
    GameObject player = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0, NULL}; // Start in the center

    // Load the player sprite
    player.texture = load_sprite(renderer, "player_sprite.bmp");
    if (!player.texture) {
        Mix_FreeMusic(music);
        Mix_CloseAudio();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main game loop
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0; // Exit the loop if the window is closed
            }
        }

        // Handle player movement
        handle_input(&player);

        // Clear the screen with a blue background
        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
        SDL_RenderClear(renderer);

        // Render the player sprite
        SDL_Rect playerRect = { (int)player.x, (int)player.y, 50, 50 }; // Adjust size as needed
        SDL_RenderCopy(renderer, player.texture, NULL, &playerRect);

        // Present the rendered frame
        SDL_RenderPresent(renderer);

        // Delay to control frame rate
        SDL_Delay(16); // ~60 FPS
    }

    // Clean up
    SDL_DestroyTexture(player.texture);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
