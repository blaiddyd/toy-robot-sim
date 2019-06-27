#include "robot.h"

struct Robot init_robot() {
    int* position = malloc(sizeof(int) * 2);
    char* direction = malloc(sizeof(char) * 5);
    direction[0] = '\0';

    position[0] = 0;
    position[1] = 0;

    struct Robot toy_robot = { position, direction };

    return toy_robot;
  
}


void eval_command(char* command, struct Robot toy_robot) {
    // check for PLACE command
   
    if (strstr(command, "PLACE")) {
        char *separated;

        while( (separated = strsep(&command, " ")) != NULL) {
        
        }

    }
    
    else if (strstr(command, "MOVE")) {

    }

    else if (strstr(command, "LEFT") || strstr(command, "RIGHT")) {

    }

    else if (strstr(command, "REPORT")) {
        
    }

  


}

void move_robot(char* pos, struct Robot toy_robot) {

    
}

void change_direction(char* direction, struct Robot toy_robot) {


}

void test_run() {
    printf("Welcome to Ekin's Toy Robot Simulator (testing mode).!\n");

}