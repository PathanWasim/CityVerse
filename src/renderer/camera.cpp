#include "camera.h"

void setCamera() {
    switch (currentCameraMode) {
        case FIRST_PERSON:
            gluLookAt(fpCameraX, fpCameraY, fpCameraZ, 
                      fpCameraX + fpLookX, fpCameraY + fpLookY, fpCameraZ + fpLookZ,
                      0.0f, 1.0f, 0.0f);
            break;
        case THIRD_PERSON:
            gluLookAt(carPosX[focusedCar] - thirdPersonDistance, 10.0f, carPosX[focusedCar] + thirdPersonDistance,
                      carPosX[focusedCar], 2.5f, 0.0f,
                      0.0f, 1.0f, 0.0f);
            break;
        case BIRD_EYE:
            gluLookAt(0.0f, 200.0f, 0.0f,
                      0.0f, 0.0f, 0.0f,
                      0.0f, 0.0f, -1.0f);
            break;
    }
}
