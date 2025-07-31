#ifndef SCENE_OBJECTS_H
#define SCENE_OBJECTS_H

#include "../common/common.h"

void drawSolidCylinder(float baseRadius, float topRadius, float height, int slices, int stacks);
void drawBench(float x, float y, float z);
void drawStreetlight(float x, float y, float z);
void drawFountain(float x, float y, float z);
void drawBillboard(float x, float y, float z);
void drawBusStop(float x, float y, float z);
void apart(float x, float y, float z);
void house(float x, float y, float z);
void house1();
void circle1(float c[20][2]);
void drawTree(float x, float y, float z);
void draw_star(GLfloat x, GLfloat y);
void stand(float x, float y, float z);
void drawSun();
void drawCar();
void drawGrid();
void drawUrbanParticles();
void drawTrafficLight(float x, float y, float z);
void updateTrafficLight(float deltaTime);

#endif // SCENE_OBJECTS_H
