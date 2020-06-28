#ifndef CAMERA_FUNCTIONS_H
#define CAMERA_FUNCTIONS_H

#include <stdint.h>

int initCamera(const uint8_t command[], uint8_t response[]);
int getCameraFB(const uint8_t command[], uint8_t response[]);

#endif // CAMERA_FUNCTIONS_H