#include "robot.h"

struct Robot init_robot() {
    int* position = malloc(sizeof(int) * 2);
    char* direction = malloc(sizeof(char) * 6);
    direction[0] = '\0';

    position[0] = 0;
    position[1] = 1;

    sprintf(direction, "RIGHT");

    struct Robot toy_robot = { position, direction };

    return toy_robot;
  
}