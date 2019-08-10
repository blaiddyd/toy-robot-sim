FLAGS = -Wall -Werror -pedantic

toy_robot: toy_robot.o robot_functions.o robot.h
	gcc -o toy_robot toy_robot.o robot_functions.o -lm

toy_robot.o: toy_robot.c robot.h
	gcc -c toy_robot.c

robot_functions.o: robot_functions.c robot.h
	gcc -c robot_functions.c

clean:
	rm -f *.o

clear:
	rm -f *.o
	rm toy_robot