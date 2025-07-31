#include "audio_manager.h"

void initOpenAL() {
    alutInit(0, nullptr);
    ALenum error = alutGetError();
    if (error != AL_NO_ERROR) {
        std::cerr << "Error initializing OpenAL: " << alutGetErrorString(error) << std::endl;
        exit(EXIT_FAILURE);
    }
}

ALuint loadSound(const char* filename) {
    ALuint buffer = alutCreateBufferFromFile(filename);
    if (buffer == AL_NONE) {
        std::cerr << "Error loading sound file: " << alutGetErrorString(alutGetError()) << std::endl;
        exit(EXIT_FAILURE);
    }
    ALuint source;
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
}

void initAmbientSounds(AudioSources* audio) {
    audio->ambientSource = loadSound("city-ambience-121693.wav");
    alSourcei(audio->ambientSource, AL_LOOPING, AL_TRUE);
    alSourcePlay(audio->ambientSource);
}

void playWeatherSound(AudioSources* audio) {
    alSourceStop(audio->rainSource);
    if (currentWeather == RAINY) {
        audio->rainSource = loadSound("rain-on-umbrella-weather-loop-112174.wav");
        alSourcei(audio->rainSource, AL_LOOPING, AL_TRUE);
        alSourcePlay(audio->rainSource);
    }
}
