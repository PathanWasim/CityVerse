# CityVerse

CityVerse is a 3D cityscape simulation written in C++ using OpenGL for graphics and OpenAL for sound. Explore a dynamic city with weather, day-night cycles, moving vehicles, and interactive camera modes.

## Features
- Real-time 3D city rendering (OpenGL)
- Dynamic weather (clear, rainy, cloudy)
- Day-night cycle with lighting changes
- Multiple camera modes: first-person, third-person, bird’s-eye
- Interactive keyboard controls
- Ambient and weather audio (OpenAL)
- Modular, maintainable codebase

## Controls
- **W/A/S/D**: Move camera
- **Q/E**: Tilt camera
- **1/2/3**: Switch camera modes
- **R**: Toggle weather
- **G**: Toggle grid
- **C**: Toggle car visibility
- **Arrow Keys/Page Up/Down**: Pan/move camera

## Requirements
- C++17 or later
- OpenGL, GLUT, and OpenAL libraries

## Build Instructions
1. Install OpenGL, GLUT (freeglut), and OpenAL (alut) for your platform.
2. Clone this repository:
   ```
   git clone https://github.com/PathanWasim/CityVerse.git
   ```
3. Build the project:
   - Use your favorite IDE or CMake, or compile manually:
   ```
   g++ src/main.cpp src/common/common.cpp src/audio/audio_manager.cpp src/weather/weather.cpp src/renderer/camera.cpp src/scene/scene_objects.cpp src/input/input_handler.cpp -o CityVerse -lGL -lGLU -lglut -lopenal -lalut
   ```
   (Adjust library flags as needed for Windows/Linux)
4. Run the executable. Make sure the WAV files are in the same directory as the executable.

## Directory Structure
```
CityVerse/
├── src/
│   ├── main.cpp
│   ├── common/
│   ├── audio/
│   ├── weather/
│   ├── renderer/
│   ├── scene/
│   └── input/
├── city-ambience-121693.wav
├── rain-on-umbrella-weather-loop-112174.wav
├── README.md
```

## Credits
- Audio: [Pixabay](https://pixabay.com/) and [freesound.org](https://freesound.org/)
- OpenGL, GLUT, OpenAL for libraries

## License
MIT
