#include "common/common.h"
#include "audio/audio_manager.h"
#include "weather/weather.h"
#include "renderer/camera.h"
#include "scene/scene_objects.h"
#include "input/input_handler.h"

AudioSources audio;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    updateDayNightCycle();
    setCamera();

    // Draw the floor
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.6, 0.4);
    glVertex3f(-200.0, 0.0, -200.0);
    glVertex3f(-200.0, 0.0, 200.0);
    glVertex3f(200.0, 0.0, 200.0);
    glVertex3f(200.0, 0.0, -200.0);
    glEnd();

    // Draw the road
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0, 0.01, -200);
    glVertex3f(0, 0.01, 200);
    glVertex3f(18, 0.01, 200);
    glVertex3f(18, 0.01, -200);
    glEnd();

    // Road markings
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(8.5, 0.02, -200);
    glVertex3f(8.5, 0.02, 200);
    glVertex3f(9.5, 0.02, 200);
    glVertex3f(9.5, 0.02, -200);
    glEnd();

    // Draw stars
    draw_star(20, 240);
    draw_star(180, 220);
    draw_star(-30, 280);
    draw_star(190, 280);
    draw_star(100, 220);
    draw_star(-230, 250);
    draw_star(-190, 210);
    draw_star(-88, 260);
    draw_star(88, 270);
    draw_star(-170, 280);

    // Draw buildings and other elements
    house1();
    drawSun();

    // Draw trees
    drawTree(-15, 1, 50);
    drawTree(-15, 1, -40);
    drawTree(-15, 1, 20);
    drawTree(-15, 1, -10);
    drawTree(-15, 1, -80);
    drawTree(-15, 1, -120);
    drawTree(-15, 1, -160);

    // Draw streetlights
    drawStreetlight(20, 1, 50);
    drawStreetlight(20, 1, -40);
    drawStreetlight(20, 1, 20);
    drawStreetlight(20, 1, -10);
    drawStreetlight(20, 1, -80);
    drawStreetlight(20, 1, -120);
    drawStreetlight(20, 1, -160);

    // Draw benches
    drawBench(25, 1, 50);
    drawBench(25, 1, -40);
    drawBench(25, 1, 20);
    drawBench(25, 1, -10);
    drawBench(25, 1, -80);
    drawBench(25, 1, -120);
    drawBench(25, 1, -160);

    // Draw fountains
    drawFountain(50, 0, 50);
    drawFountain(50, 0, -50);

    // Draw traffic lights
    drawTrafficLight(-20, 0, 50);
    drawTrafficLight(-20, 0, -50);
    drawTrafficLight(20, 0, 50);
    drawTrafficLight(-30, 0, -50);

    // Draw billboards
    drawBillboard(-50, 0, 50);
    drawBillboard(-50, 0, -50);

    // Draw bus stops
    drawBusStop(40, 0, 60);
    drawBusStop(40, 0, -60);

    drawCar();
    drawGrid();
    drawUrbanParticles();
    drawWeatherEffects();
    if (currentWeather == RAINY) {
        drawRain();
    }

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glEnable(GLUT_MULTISAMPLE);
    glutInitWindowSize(1100, 1100);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("UrbanScope 3D");
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glutSpecialFunc(handleSpecialKeys);
    setupFog();
    for (int i = 0; i < NUM_CARS; i++) {
        carPosX[i] = -200.0f + (i * 20);
        carSpeed[i] = 1.0f + ((rand() % 5) / 10.0f);
        carVisible[i] = true;
    }
    initOpenAL();
    initAmbientSounds(&audio);
    playWeatherSound(&audio);
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutReshapeFunc(handleResize);
    glutTimerFunc(0, handleTimer, 0);
    glutMainLoop();
    return 0;
}
