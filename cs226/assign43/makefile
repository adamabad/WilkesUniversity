CFLAGS = -c -Wall -g
LFLAGS = -g -o assign43

assign43: assign43.o listj.o
	g++ assign43.o listj.o $(LFLAGS)

assign43.o: assign43.cpp listj.h
	g++ $(CFLAGS) assign43.cpp

listj.o: listj.cpp listj.h
	g++ $(CFLAGS) listj.cpp

clean:
	rm -f assign43 *.o *~ *#
