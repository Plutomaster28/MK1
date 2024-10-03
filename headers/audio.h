#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL_mixer.h> // Include SDL_mixer header

// Declare extern variable
extern Mix_Music* music;

// Function declarations...
void init_audio();
void load_music(const char* filename);
void play_music();

#endif // AUDIO_H
