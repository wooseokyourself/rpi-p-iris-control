main.out: main.o
	g++ -o main.out -lwiringPi main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm -f *.o *.out