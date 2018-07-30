
main: main.o calendar.o
	gcc main.o calendar.o -o main

main.o: main.c
	gcc -Wall -Werror -Wextra -g -c main.c

calendar.o: calendar.c calendar.h
	gcc -Wall -Werror -Wextra -g -c calendar.c

clean:
	rm -f *.o *.txt main