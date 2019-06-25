#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POS = 4

struct Robot
{
    int* position;
    char* direction;
    
};

struct Robot init_robot();