#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "../common/common.h"

void handleKeyboard(unsigned char key, int x, int y);
void handleSpecialKeys(int key, int x, int y);
void handleResize(int width, int height);
void handleTimer(int);

#endif // INPUT_HANDLER_H
