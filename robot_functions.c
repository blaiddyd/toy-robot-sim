#include "robot.h"

struct Robot init_robot() {
    int* position = malloc(sizeof(int) * 2);
    char *direction = malloc(sizeof(char) * 23);
    bool place_issued = false;

    position[0] = 0;
    position[1] = 0;

    struct Robot toy_robot = { position, direction, place_issued };

    return toy_robot;
  
}

void change_direction(char* direction, struct Robot toy_robot) {
    strcpy(toy_robot.direction, direction);
}

void place_robot(char *position[], struct Robot toy_robot) {
    if (atoi(position[0]) < 4 && atoi(position[0]) > 0) {
        toy_robot.position[0] = atoi(position[0]);
    }
    else {
        printf("Placement causes your robot to fall off the table!\n");
    }

    if (atoi(position[1]) < 4 && atoi(position[1]) > 0) {
        toy_robot.position[1] = atoi(position[1]);
    }
    else {
        printf("Placement causes your robot to fall off the table!\n");
    }

    change_direction(position[2], toy_robot);
    
}

void eval_command(char* command, struct Robot toy_robot) {

    if (strstr(command, "PLACE")) {
        char *separated;
        char *found_position;
        char *parsed_position[4];
        toy_robot.place_issued = true;
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

                    place_robot(parsed_position, toy_robot);
                }
                else {
                    printf("PLACE command issued without any specified direction.\n");
                }
            }
        
        }
    }
    
    else if (strstr(command, "MOVE") && toy_robot.place_issued == true) {
        if (strstr(toy_robot.direction, "WEST")) {
            if (toy_robot.position[0] <= 4 && toy_robot.position[0] >= 0) {
                toy_robot.position[0]--;
            }
            else {
                printf("Command issued would have resulted in your robot falling off the table!\n");
                return;
            }
        }

        else if (strstr(toy_robot.direction, "EAST")) {
            if (toy_robot.position[0] < 4 && toy_robot.position[0] >= 0) {
                toy_robot.position[0]++;
            }

            else {
                printf("Command issued would have resulted in your robot falling off the table!\n");
                return;
            }
        }

        else if (strstr(toy_robot.direction, "NORTH")) {
            if (toy_robot.position[1] < 4 && toy_robot.position[1] >= 0) {
                toy_robot.position[1]++;
            }

            else {
                printf("Command issued would have resulted in your robot falling off the table!\n");
                return;
            }
        }

        else if (strstr(toy_robot.direction, "SOUTH")) {
            if (toy_robot.position[1] <= 4 && toy_robot.position[1] >= 0) {
                toy_robot.position[1]--;
            }

            else {
                printf("Command issued would have resulted in your robot falling off the table!\n");
                return;
            }
        }
        
    }

    else if (strstr(command, "LEFT") && toy_robot.place_issued == true) {
        if (strstr(toy_robot.direction, "EAST")) {
            change_direction("NORTH", toy_robot);
        }
        else if (strstr(toy_robot.direction, "WEST")) {
            change_direction("SOUTH", toy_robot);
        }
        else if (strstr(toy_robot.direction, "NORTH")) {
            change_direction("WEST", toy_robot);
        }
        else if (strstr(toy_robot.direction, "SOUTH")) {
            change_direction("EAST", toy_robot);
        }
        else {
            printf("Cannot change the direction of your toy robot.\n");
        }
        
    }

    else if (strstr(command, "RIGHT") && toy_robot.place_issued == true) {
        if (strstr(toy_robot.direction, "EAST")) {
            change_direction("SOUTH", toy_robot);
        }
        else if (strstr(toy_robot.direction, "WEST")) {
            change_direction("NORTH", toy_robot);
        }
        else if (strstr(toy_robot.direction, "NORTH")) {
            change_direction("EAST", toy_robot);
        }
        else if (strstr(toy_robot.direction, "SOUTH")) {
            change_direction("WEST", toy_robot);
        }
        else {
            printf("Cannot change the direction of your toy robot.\n");
        }
    }

    else if (strstr(command, "REPORT") && toy_robot.place_issued == true) {
        printf("Position of your toy robot: %d,%d,%s\n", toy_robot.position[0], toy_robot.position[1], toy_robot.direction);
    }

    else if (toy_robot.place_issued == false) {
        printf("Please input a PLACE command to issue any further commands.\n");
    }

    else {
        printf("Unrecognized command. Please try again.\n");
    }

}


void test_run() {
    printf("Welcome to Ekin's Toy Robot Simulator (testing mode).!\n");

}