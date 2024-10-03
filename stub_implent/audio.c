#include "audio.h"
#include <SDL2/SDL_mixer.h>
#include <stdio.h>

Mix_Music* music = NULL; // Define the music variable

void init_audio() {
    // Initialize SDL_mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

// Load a music file (stub)
void load_music(const char* filename) {
    music = Mix_LoadMUS(filename);
    if (!music) {
        printf("Failed to load music: %s\n", Mix_GetError());
    }
}

// Play the loaded music (stub)
void play_music() {
    if (music) {
        Mix_PlayMusic(music, -1); // -1 means loop indefinitely
    }
}
