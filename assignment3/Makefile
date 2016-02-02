SOURCES = directory.c main.c
HEADERS = directory.h 
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -std=c99 -g

%.o: %.c
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

clean:
	$(RM) main $(OBJECTS)


