exe: main.o race.o racers.o segments.o
	g++ -g -Wall main.o race.o racers.o segments.o -o exe

race.o: race.h racers.o segments.o
	g++ -g -Wall -c race.cpp

racers.o: racers.h
	g++ -g -Wall -c racers.cpp

segments.o: segments.h
	g++ -g -Wall -c segments.cpp

main.o: segments.o racers.o race.o
	g++ -g -Wall -c main.cpp

clean:
	rm *~ exe *.o -v