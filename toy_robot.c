#include "robot.h"

int main(int argc, char **argv) {
    int test_flag = 0;
    char *command = malloc(sizeof(char) * 20);

    printf("Welcome to Ekin's Toy Robot Simulator.\n");

    struct Robot toy_robot = init_robot();

    return 0;
}
