all: main
    
main: main.o game.o
	g++ -o main main.o game.o 

main.o:
	g++ -c main.cpp

game.o:
	g++ -c game.cpp

clean:
	rm main.o game.o main