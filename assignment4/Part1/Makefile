CXX = g++
CXXFLAGS = -g -std=c++11
ROT13_OBJECTS = test-rot13cipher.o rot13cipher.o ioutils.o
CAESAR_OBJECTS = test-caesar.o caesar.o ioutils.o
DATE_OBJECTS = test-date.o date.o ioutils.o

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: test-rot13cipher test-caesar test-date

test-rot13cipher: $(ROT13_OBJECTS)
	$(CXX) -o $@ $(ROT13_OBJECTS)

test-caesar: $(CAESAR_OBJECTS)
	$(CXX) -o $@ $(CAESAR_OBJECTS)

test-date: $(DATE_OBJECTS)
	$(CXX) -o $@ $(DATE_OBJECTS)

clean: 
	$(RM) *.o test-rot13cipher test-caesar test-date