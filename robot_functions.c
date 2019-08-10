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

int[][] init_board() {
    int board[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = false;
        }
    }

    return board;
}

void place_robot(char *position[], struct Robot toy_robot) {
    if (atoi(position[0]) < 4 && atoi(position[0]) > 0) {
        toy_robot.position[0] = atoi(position[0]);
    }

    if (atoi(position[1]) < 4 && atoi(position[1]) > 0) {
        toy_robot.position[1] = atoi(position[1]);
    }
    
    toy_robot.direction = position[2];

    printf("Robot's coordinates: %d,%d\n", toy_robot.position[0], toy_robot.position[1]);
    printf("Robot's direction: %s\n", toy_robot.direction);
}

void eval_command(char* command, struct Robot toy_robot) {
    // check for PLACE command
   
    if (strstr(command, "PLACE")) {
        char *separated;
        char *found_position;
        char *parsed_position[4];
        int count = 0;

        while( (separated = strsep(&command, " ")) != NULL) {
            if (strstr(separated, "PLACE")) {
                continue;
            }
            else {
                if (strstr(separated, "WEST") || strstr(separated, "EAST") || strstr(separated, "NORTH") || strstr(separated, "SOUTH")) {
                    while ( (found_position = strsep(&separated, ",")) != NULL) {
                       count++;
                       if (count > 3) {
                           break;
                       }

                       parsed_position[count - 1] = found_position;
                    }
                }
            }
        
        }
        place_robot(parsed_position, toy_robot);
    }
    
    else if (strstr(command, "MOVE")) {
        
    }

    else if (strstr(command, "LEFT") || strstr(command, "RIGHT")) {
        //
    }

    else if (strstr(command, "REPORT")) {
        
    }

}

void change_direction(char* direction, struct Robot toy_robot) {
    toy_robot.direction = '\0';
    toy_robot.direction = direction;
}

void test_run() {
    printf("Welcome to Ekin's Toy Robot Simulator (testing mode).!\n");

}