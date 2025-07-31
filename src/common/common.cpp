#include "common.h"

// Common constants
const int NUM_CARS = 3;
const float RED_DURATION = 5.0f;
const float GREEN_DURATION = 5.0f;
const float YELLOW_DURATION = 2.0f;

// Global variables definitions
float cc[20][2];
float cameraSpeed = 5.0f;
float mouseSensitivity = 0.2f;
float timeOfDay = 0.0f;
float lightIntensity = 1.0f;
bool showGrid = false;
float carPosX[NUM_CARS];
float carSpeed[NUM_CARS];
bool carVisible[NUM_CARS];

TrafficLightState trafficLightState = GREEN;
float trafficLightTimer = 0.0f;
WeatherType currentWeather = CLEAR;
float weatherIntensity = 0.0f;
CameraMode currentCameraMode = FIRST_PERSON;

float thirdPersonDistance = 50.0f;
int focusedCar = 0;
float fpCameraX = 0.0f, fpCameraY = 5.0f, fpCameraZ = 100.0f;
float fpLookX = 0.0f, fpLookY = 0.0f, fpLookZ = -1.0f;
float cameraPosX = 0.0f;
float cameraPosY = 5.0f;
float cameraPosZ = 100.0f;
float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;

// Common geometry variables
float h = 5.0f;
float h1 = 6.0f;
float d1 = 4.0f;
float g = 1.0f;
float g1 = 2.0f;
