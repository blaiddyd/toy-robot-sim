#include "robot.h"

int main(int argc, char **argv) {
    int test_flag, opt_res;
    char *command = malloc(sizeof(char) * 20);

    while(( opt_res = getopt(argc, argv, "ut")) != -1) {
        switch (opt_res) {
        case 'u':
           test_flag = 0;
            break;
        case 't':
            test_flag = 1;
            break;
        default:
            test_flag = 0;
            break;
        }
    }

    if (test_flag == 1) {
        test_run();
    }
   
    else {
        printf("Welcome to Ekin's Toy Robot Simulator (input mode)!\n");
        printf("Meet your very own toy robot, Nezuko!\n");

        struct Robot toy_robot = init_robot();
        char* command = malloc(sizeof(char) * 256);

        printf("Enter your first command for Nezuko: \n");

        while (true) {
            fgets(command, 256, stdin);
            eval_command(command, toy_robot);
            command[0] = '\0';
        }

        free(command);
        free(toy_robot.position);
        free(toy_robot.direction);
    }

    return 0;
}
