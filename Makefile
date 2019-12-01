CC = gcc
CFLAGS = -Wall

exec:	main.c image.o propager.o traitement.o
	$(CC) $(CFLAGS) $^ -o exec

image.o:	image.c image.h
	$(CC) $(CFLAGS) $< -c

propager.o:	propager.c image.h propager.h
	$(CC) $(CFLAGS) $< -c

traitement.o:	traitement.c image.h propager.h traitement.h
	$(CC) $(CFLAGS) $< -c

clean:
	rm -f *.o *.out *.exe exec 
