#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

bool place_issued;

struct Robot
{
    int* position;
    char* direction;
    
};

struct Robot init_robot();
void test_run();
void eval_command(char* command, struct Robot toy_robot);