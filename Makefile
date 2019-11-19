CC = gcc
CFLAGS = -Wall



exec:	image.c
	$(CC) $(CFLAGS) $< -c


clean:
	rm -f *.o *.out exec
