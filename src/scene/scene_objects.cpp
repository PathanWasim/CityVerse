#include "scene_objects.h"

void drawSolidCylinder(float baseRadius, float topRadius, float height, int slices, int stacks) {
    GLUquadric* quad = gluNewQuadric();
    gluCylinder(quad, baseRadius, topRadius, height, slices, stacks);
    gluDeleteQuadric(quad);
}

// Implementations of drawBench, drawStreetlight, drawFountain, drawBillboard, drawBusStop, apart, house, house1, circle1, drawTree, draw_star, stand, drawSun, drawCar, drawGrid, drawUrbanParticles, drawTrafficLight, updateTrafficLight

// ... (to be filled in with the code from the original file, extracted into this module)
