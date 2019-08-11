#include "robot.h"

struct Robot init_robot() {
    int* position = malloc(sizeof(int) * 2);
    char *direction = malloc(sizeof(char) * 100);

    position[0] = 0;
    position[1] = 0;

    struct Robot toy_robot = { position, direction };

    return toy_robot;
  
}

void change_direction(char* direction, struct Robot toy_robot) {
    if (strlen(direction) > 6 || strlen(direction) == 0) {
        printf("Invalid direction parameter. Please try again.\n");
    }
    strcpy(toy_robot.direction, direction);
}

void place_robot(char *position[], struct Robot toy_robot) {

    if (atoi(position[0]) < 4 && atoi(position[0]) > 0) {
        toy_robot.position[0] = atoi(position[0]);
    }
    else {
        printf("Placement would have caused Nezuko to fall off the table or was invalid!\n");
    }

    if (atoi(position[1]) < 4 && atoi(position[1]) > 0) {
        toy_robot.position[1] = atoi(position[1]);
    }
    else {
        printf("Placement would have caused Nezuko to fall off the table or was invalid!\n");
    }

    change_direction(position[2], toy_robot);
    
}

void eval_command(char* command, struct Robot toy_robot) {

    if (strstr(command, "PLACE")) {
        char *separated;
        char *found_position;
        char *parsed_position[4];
        int count = 0;
        place_issued = true;


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
                    printf("PLACE command issued without any specified/recognized direction.\n");
                }
            }
        
        }
    }
    
    else if (strstr(command, "MOVE") && place_issued) {
        if (strstr(toy_robot.direction, "WEST")) {
            if (toy_robot.position[0] <= 4 && toy_robot.position[0] > 0) {
                toy_robot.position[0]--;
            }
            else {
                printf("Command issued would have resulted in Nezuko falling off the table!\n");
                return;
            }
        }

        else if (strstr(toy_robot.direction, "EAST")) {
            if (toy_robot.position[0] < 4 && toy_robot.position[0] >= 0) {
                toy_robot.position[0]++;
            }

            else {
                printf("Command issued would have resulted in Nezuko falling off the table!\n");
                return;
            }
        }

        else if (strstr(toy_robot.direction, "NORTH")) {
            if (toy_robot.position[1] < 4 && toy_robot.position[1] >= 0) {
                toy_robot.position[1]++;
            }

            else {
                printf("Command issued would have resulted in Nezuko falling off the table!\n");
                return;
            }
        }

        else if (strstr(toy_robot.direction, "SOUTH")) {
            if (toy_robot.position[1] <= 4 && toy_robot.position[1] > 0) {
                toy_robot.position[1]--;
            }

            else {
                printf("Command issued would have resulted in Nezuko falling off the table!\n");
                return;
            }
        }
        
    }

    else if (strstr(command, "LEFT") && place_issued) {
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
            printf("Cannot change the direction of Nezuko.\n");
        }
        
    }

    else if (strstr(command, "RIGHT") && place_issued) {
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
            printf("Cannot change the direction of Nezuko.\n");
        }
    }

    else if (strstr(command, "REPORT") && place_issued) {
        printf("Position of your toy robot: %d,%d,%s\n", toy_robot.position[0], toy_robot.position[1], toy_robot.direction);
    }

    else if (place_issued == false) {
        printf("Please input a PLACE command to issue any further commands.\n");
    }

    else {
        printf("Unrecognized command. Please try again.\n");
    }

}


void test_run() {
    printf("Welcome to Ekin's Toy Robot Simulator (testing mode)!\n");
    printf("Meet your very own toy robot, Nezuko!\n");

    struct Robot test_robot = init_robot();
    char* command = malloc(sizeof(char) * 256);

    printf("Command: MOVE\n");
    strcpy(command, "MOVE");
    eval_command(command, test_robot);

    printf("Command: PLACE 1,2,NORTH\n");
    strcpy(command, "PLACE 1,2,NORTH");
    eval_command(command, test_robot);

    printf("Command: REPORT\n");
    strcpy(command, "REPORT");
    eval_command(command, test_robot);

    printf("Command: MOVE\n");
    strcpy(command, "MOVE");
    eval_command(command, test_robot);

    printf("Command: HELLO THERE!\n");
    strcpy(command, "HELLO THERE");
    eval_command(command, test_robot);
    
    printf("Command: MOVE\n");
    strcpy(command, "MOVE");
    eval_command(command, test_robot);

    printf("Command: MOVE\n");
    strcpy(command, "MOVE");
    eval_command(command, test_robot);

    printf("Command: LEFT\n");
    strcpy(command, "LEFT");
    eval_command(command, test_robot);

    printf("Command: LEFT\n");
    strcpy(command, "LEFT");
    eval_command(command, test_robot);

    printf("Command: RIGHT\n");
    strcpy(command, "RIGHT");
    eval_command(command, test_robot);

    strcpy(command, "REPORT");
    eval_command(command, test_robot);
}