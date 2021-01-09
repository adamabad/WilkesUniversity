CFLAGS = -c -Wall -g
LFLAGS = -g -o assign4a

assign4a: assign4a.o list.o
	g++ assign4a.o list.o $(LFLAGS)

assign4a.o: assign4a.cpp list.h
	g++ $(CFLAGS) assign4a.cpp

list.o: list.cpp list.h
	g++ $(CFLAGS) list.cpp

clean:
	rm -f assign4a *.o *~ *#
