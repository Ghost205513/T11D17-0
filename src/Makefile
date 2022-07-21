CC=gcc

CFLAGS=-Wall -Werror -Wextra -std=c11

door_struct :  dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c -D doors_sort -o dmanager_module.o
	$(CC) dmanager_module.o -o ./../build/Quest_1 -lm

clean :
	rm -f *.o
	rm -f ./../build/Quest_*

