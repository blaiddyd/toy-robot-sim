#include "robot.h"

struct Robot init_robot() {
    int* position = malloc(sizeof(int) * 2);
    char* direction = malloc(sizeof(char) * 20);
    direction[0] = '\0';

    position[0] = 0;
    position[1] = 0;

    struct Robot toy_robot = { position, direction };

    return toy_robot;
  
}

void eval_command(char* command, struct Robot toy_robot) {
    // check for place command

}

void change_position(char* pos, struct Robot toy_robot) {
    
}