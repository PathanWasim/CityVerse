#ifndef COMMON_H
#define COMMON_H

#include <GL/glut.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Common constants
extern const int NUM_CARS;
extern const float RED_DURATION;
extern const float GREEN_DURATION;
extern const float YELLOW_DURATION;

// Common enums
enum TrafficLightState {
    RED,
    GREEN,
    YELLOW
};

enum WeatherType {
    CLEAR,
    RAINY,
    CLOUDY
};

enum CameraMode {
    FIRST_PERSON,
    THIRD_PERSON,
    BIRD_EYE
};

// Global variables (extern declarations)
extern float cc[20][2];
extern float cameraSpeed;
extern float mouseSensitivity;
extern float timeOfDay;
extern float lightIntensity;
extern bool showGrid;
extern float carPosX[];
extern float carSpeed[];
extern bool carVisible[];

extern TrafficLightState trafficLightState;
extern float trafficLightTimer;
extern WeatherType currentWeather;
extern float weatherIntensity;
extern CameraMode currentCameraMode;

extern float thirdPersonDistance;
extern int focusedCar;
extern float fpCameraX, fpCameraY, fpCameraZ;
extern float fpLookX, fpLookY, fpLookZ;
extern float cameraPosX, cameraPosY, cameraPosZ;
extern float cameraAngleX, cameraAngleY;

// Common geometry variables
extern float h, h1, d1, g, g1;

#endif // COMMON_H
