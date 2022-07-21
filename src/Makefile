CC=gcc

CFLAGS=-Wall -Werror -Wextra -std=c11

door_struct :  dmanager_module.o
	$(CC) dmanager_module.o -o ./../build/Quest_1 -lm
	rm -f *.o

list_test : list.o list_test.o
	$(CC) list.o list_test.o -o ./../build/Quest_2 -lm
	rm -f *.o

dmanager_module.o : dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c -o dmanager_module.o

list.o : list.c
	$(CC) $(CFLAGS) -c list.c -o list.o

list_test.o : list_test.c
	$(CC) $(CFLAGS) -c list_test.c -o list_test.o

clean :
	rm -f ./../build/Quest_*

