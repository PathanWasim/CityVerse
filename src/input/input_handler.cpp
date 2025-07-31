#include "input_handler.h"
#include "../scene/scene_objects.h"
#include "../weather/weather.h"

void handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': case 'A':
            cameraPosX -= 5.0f * cos(cameraAngleY * M_PI / 180.0f);
            cameraPosZ -= 5.0f * sin(cameraAngleY * M_PI / 180.0f);
            break;
        case 'd': case 'D':
            cameraPosX += 5.0f * cos(cameraAngleY * M_PI / 180.0f);
            cameraPosZ += 5.0f * sin(cameraAngleY * M_PI / 180.0f);
            break;
        case 'w': case 'W':
            cameraPosX += 5.0f * sin(cameraAngleY * M_PI / 180.0f);
            cameraPosZ -= 5.0f * cos(cameraAngleY * M_PI / 180.0f);
            break;
        case 's': case 'S':
            cameraPosX -= 5.0f * sin(cameraAngleY * M_PI / 180.0f);
            cameraPosZ += 5.0f * cos(cameraAngleY * M_PI / 180.0f);
            break;
        case 'q': case 'Q':
            cameraAngleX -= 2.0f;
            break;
        case 'e': case 'E':
            cameraAngleX += 2.0f;
            break;
        case 'r': case 'R':
            currentWeather = (WeatherType)((currentWeather + 1) % 3);
            break;
        case 'g': case 'G':
            showGrid = !showGrid;
            break;
        case 'c': case 'C':
            for (int i = 0; i < NUM_CARS; i++) {
                carVisible[i] = !carVisible[i];
            }
            if (carVisible[0]) {
                glutTimerFunc(0, handleTimer, 0);
            }
            break;
        case '1':
            currentCameraMode = FIRST_PERSON;
            break;
        case '2':
            currentCameraMode = THIRD_PERSON;
            break;
        case '3':
            currentCameraMode = BIRD_EYE;
            break;
    }
    glutPostRedisplay();
}

void handleSpecialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_PAGE_UP:
        cameraPosY += 5.0f;
        break;
    case GLUT_KEY_PAGE_DOWN:
        cameraPosY -= 5.0f;
        break;
    case GLUT_KEY_LEFT:
        cameraAngleY -= 2.0f;
        break;
    case GLUT_KEY_RIGHT:
        cameraAngleY += 2.0f;
        break;
    }
    glutPostRedisplay();
}

void handleResize(int width, int height) {
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, width / height, 1.0, 600.0);
    glTranslatef(0.0, -15.0, -320.0);
    glMatrixMode(GL_MODELVIEW);
}

void handleTimer(int) {
    float deltaTime = 0.016f;
    updateTrafficLight(deltaTime);
    for (int i = 0; i < NUM_CARS; i++) {
        if (carVisible[i]) {
            if (trafficLightState == GREEN || (carPosX[i] < -20 || carPosX[i] > 20)) {
                carPosX[i] += carSpeed[i];
            }
            if (carPosX[i] > 200) {
                carPosX[i] = -200;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, handleTimer, 0);
}
