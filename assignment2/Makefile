SOURCES = triangle1.c triangle2.c main.c
HEADERS = triangle.h 
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = gcc
CFLAGS = -std=c99 -g

%.o: %.c
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

tests: test-triangle

test-triangle: test-triangle.o triangle.o
	$(CC) -o $@ test-triangle.o triangle.o $(LIBS)

test-triangle: test-triangle.o triangle.o
	$(CC) -o $@ test-triangle.o triangle.o $(LIBS)

test-main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

test-test: test.o triangle.o 
	$(CC) -o $@ test.o triangle.o  $(LIBS)

clean: 
	$(RM) main $(OBJECTS) test-*
