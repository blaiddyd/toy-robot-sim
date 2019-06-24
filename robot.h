#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "robot_functions.c"

#define MAX_POS = 4

struct Robot
{
    int* position;
    char* direction;
    
};

struct Robot init_robot();