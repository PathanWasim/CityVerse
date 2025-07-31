#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include "../common/common.h"

// Audio sources
typedef struct {
    ALuint ambientSource;
    ALuint rainSource;
    ALuint thunderSource;
} AudioSources;

// Audio functions
void initOpenAL();
void initAmbientSounds(AudioSources* audio);
void playWeatherSound(AudioSources* audio);
ALuint loadSound(const char* filename);

#endif // AUDIO_MANAGER_H
