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
        printf("Welcome to Ekin's Toy Robot Simulator (user mode)!\n");
        
        struct Robot toy_robot = init_robot();
        bool place_invoked = false;
        char* command = malloc(sizeof(char) * 256);

        printf("Enter your first command for the robot: \n");
        fgets(command, 256, stdin);

        printf("Command entered: %s \n", command);

        eval_command(command, toy_robot);

    }

   

    return 0;
}
